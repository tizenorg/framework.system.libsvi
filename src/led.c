/*
 * libfeedback
 * Copyright (c) 2012 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <vconf.h>

#include "feedback-ids.h"
#include "common.h"
#include "log.h"
#include "dbus.h"
#include "devices.h"

#define FEEDBACK_LED_DIR			FEEDBACK_DATA_DIR"/led"
#define FEEDBACK_LED_TOUCH_DIR		FEEDBACK_LED_DIR"/touch"
#define FEEDBACK_LED_OPER_DIR		FEEDBACK_LED_DIR"/operation"
#define FEEDBACK_LED_NOTI_DIR		FEEDBACK_LED_DIR"/notification"

#define METHOD_PLAY_PATTERN			"PlayPattern"
#define METHOD_STOP_PATTERN			"StopPattern"
#define METHOD_SET_BRIGHTNESS		"SetBrightness"

#define ITERATION_ONCE				1
#define NO_NOTI						0

static const char* led_file[] = {
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : GENERAL */
	NULL,
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : TEXT_NUMERIC_INPUT */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : DAILER */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	/* TOUCH : H/W OR SOFT TOUCH : HOLD(TAP & HOLD) */
	NULL,
	/* TOUCH : H/W OR SOFT TOUCH : MULTI TAP */
	NULL,
	/* TOUCH : H/W OR SOFT TOUCH : TAP */
	NULL,
	/* TOUCH : H/W OR SOFT TOUCH : TAP & HOLD */
	NULL,

	/* NOTIFICATION : INCOMING : MESSAGE */
	FEEDBACK_LED_NOTI_DIR"/message.led",
	/* NOTIFICATION : INCOMING : MESSAGE ALERT ON CALL */
	FEEDBACK_LED_NOTI_DIR"/message_on_call.led",
	/* NOTIFICATION : INCOMING : EMAIL */
	FEEDBACK_LED_NOTI_DIR"/email.led",
	/* NOTIFICATION : INCOMING : EMAIL ALERT ON CALL */
	FEEDBACK_LED_NOTI_DIR"/email_on_call.led",
	/* NOTIFICATION : ALARM : WAKEUP */
	FEEDBACK_LED_NOTI_DIR"/alarm.led",
	/* NOTIFICATION : ALARM : WAKEUP ALERT ON CALL */
	FEEDBACK_LED_NOTI_DIR"/alarm_on_call.led",
	/* NOTIFICATION : ALARM : SCHEDULE */
	FEEDBACK_LED_NOTI_DIR"/alarm.led",
	/* NOTIFICATION : ALARM : SCHEDULE ALERT ON CALL */
	FEEDBACK_LED_NOTI_DIR"/alarm_on_call.led",
	/* NOTIFICATION : ALARM : TIMER */
	FEEDBACK_LED_NOTI_DIR"/alarm.led",
	/* NOTIFICATION : ALARM : TIMER ALERT ON CALL */
	FEEDBACK_LED_NOTI_DIR"/alarm_on_call.led",
	/* NOTIFICATION : GENERAL(TICKER/IM/SMS ETC) */
	NULL,
	/* NOTIFICATION : GENERAL(TICKER/IM/SMS ETC) ALERT ON CALL */
	NULL,
	/* NOTIFICATION : SMART ALERT */
	NULL,

	/* OPERATION : POWER ON/OFF */
	FEEDBACK_LED_OPER_DIR"/short.led",
	FEEDBACK_LED_OPER_DIR"/long.led",
	/* OPERATION : CHARGECONN */
	NULL,
	/* OPERATION : CHARGECONN ALERT ON CALL */
	NULL,
	/* OPERATION : CHARGING ERROR */
	NULL,
	/* OPERATION : CHARGING ERROR ON CALL */
	NULL,
	/* OPERATION : FULLCHAREGED */
	NULL,
	/* OPERATION : FULLCHAREGED ALERT ON CALL */
	NULL,
	/* OPERATION : LOW BATTERY */
	FEEDBACK_LED_OPER_DIR"/twice.led",
	/* OPERATION : LOW BATTERY ALERT ON CALL */
	FEEDBACK_LED_OPER_DIR"/operation_on_call.led",
	/* OPERATION : LOCK/UNLOCK */
	NULL,
	NULL,
	NULL,
	NULL,
	/* OPERATION : CALL CONNECT/ DISCONNECT */
	NULL,
	NULL,
	/* OPERATION : OUTGOING CALL */
	NULL,
	/* OPERATION : MINUTE MINDER */
	NULL,
	/* OPERATION : VIBRATION ON */
	NULL,
	/* OPERATION : SILENT OFF */
	NULL,
	/* OPERATION : CONNECTED */
	NULL,
	/* OPERATION : DISCONNECTED */
	NULL,
	/* OPERATION : BT PARING */
	NULL,
	/* OPERATION : SCREEN CAPTURE */
	NULL,
	/* OPERATION : LIST RE-ORDER */
	NULL,
	/* OPERATION : LIST SLIDER */
	NULL,
	/* OPERATION : VOLUME KEY */
	NULL,
	/* OPERATION : MMS */
	NULL,
	/* OPERATION : HOURLY ALERT */
	NULL,

	/* OPERATION : SAFETY ALERT */
	NULL,
	/* OPERATION : ACCIDENT DETECT */
	NULL,
	/* OPERATION : SEND SOS MESSAGE */
	NULL,
	/* OPERATION : EMERGENCY BUZZER */
	NULL,
	/* OPERATION : SAFETY LOW POWER */
	NULL,
	/* OPERATION : CMAS */
	NULL,
	/* OPERATION : SPEED UP */
	NULL,
	/* OPERATION : SLOW DOWN */
	NULL,
	/* OPERATION : KEEP THIS PACE */
	NULL,
	/* OPERATION : GOAL ACHIEVED */
	NULL,
	/* OPERATION : EXERCISE COUNT */
	NULL,
	/* OPERATION : START CUE */
	NULL,

	/* OPERATION : SUCCESS */
	NULL,
	/* OPERATION : FAILURE */
	NULL,
};

static int ledstatus;
static int torchon;

static int led_play_pattern(const char *path, int count)
{
	char *arr[2];
	char buf_count[32];

	arr[0] = (char*)path;
	snprintf(buf_count, sizeof(buf_count), "%d", count);
	arr[1] = buf_count;

	return dbus_method_sync(DEVICED_BUS_NAME, DEVICED_PATH_LED,
			DEVICED_INTERFACE_LED, METHOD_PLAY_PATTERN,
			"si", arr);
}

static inline int led_stop_pattern(void)
{
	return dbus_method_sync(DEVICED_BUS_NAME, DEVICED_PATH_LED,
			DEVICED_INTERFACE_LED, METHOD_STOP_PATTERN,
			NULL, NULL);
}

static int led_set_brt(int brt)
{
	char *arr[2];
	char buf_val[32];
	char buf_enable[32];

	snprintf(buf_val, sizeof(buf_val), "%d", brt);
	arr[0] = buf_val;
	snprintf(buf_enable, sizeof(buf_enable), "%d", NO_NOTI);
	arr[1] = buf_enable;

	return dbus_method_sync(DEVICED_BUS_NAME, DEVICED_PATH_LED,
			DEVICED_INTERFACE_LED, METHOD_SET_BRIGHTNESS,
			"ii", arr);
}

static void feedback_ledstatus_cb(keynode_t *key, void* data)
{
	ledstatus = vconf_keynode_get_bool(key);
}

static void feedback_torchon_cb(keynode_t *key, void* data)
{
	torchon = vconf_keynode_get_bool(key);
}

static int change_symlink(const char *sym_path, const char *new_path)
{
	struct stat buf;

	assert(sym_path != NULL && strlen(sym_path));
	assert(new_path != NULL && strlen(new_path));

	/* check symbolic link file existence */
	if (stat(sym_path, &buf)) {
		_E("file(%s) is not presents", sym_path);
		return -ENOENT;
	}

	if (stat(new_path, &buf)) {
		_E("file(%s) is not presents", new_path);
		return -ENOENT;
	}

	if (unlink(sym_path) < 0)
		_D("unlink(%s) : %s", sym_path, strerror(errno));

	if (symlink(new_path, sym_path) < 0) {
		_E("symlink(%s) : %s", sym_path, strerror(errno));
		return -EPERM;
	}

	return 0;
}

static int restore_default_file(feedback_pattern_e pattern)
{
	char default_path[PATH_MAX] = {0,};
	const char *cur_path;
	char *temp;
	int ret;

	cur_path = led_file[pattern];
	/* if there isn't cur_path, it already returns before calling this api */
	if (cur_path == NULL || strlen(cur_path) == 0) {
		_E("Invalid parameter : cur_path(NULL)");
		return -EPERM;
	}

	temp = strcat(default_path, FEEDBACK_ORIGIN_DATA_DIR);
	strcat(temp, cur_path+strlen(FEEDBACK_DATA_DIR));
	_D("default_path : %s", default_path);

	ret = change_symlink(cur_path, default_path);
	if (ret < 0) {
		_E("change_symlink is failed");
		return -EPERM;
	}

	return 0;
}

static void led_init(void)
{
	/* Led Init */
	if(vconf_get_bool(VCONFKEY_SETAPPL_ACCESSIBILITY_LED_NOTIFY, &ledstatus) < 0)
		_W("VCONFKEY_SETAPPL_ACCESSIBILITY_LED_NOTIFY ==> FAIL!!");

	/* Assistive light */
	if(vconf_get_bool(VCONFKEY_SETAPPL_ACCESSIBILITY_TORCH_LIGHT, &torchon) < 0)
		_W("VCONFKEY_SETAPPL_ACCESSIBILITY_TORCH_LIGHT ==> FAIL!!");

	/* add watch for status value */
	vconf_notify_key_changed(VCONFKEY_SETAPPL_ACCESSIBILITY_LED_NOTIFY, feedback_ledstatus_cb, NULL);
	vconf_notify_key_changed(VCONFKEY_SETAPPL_ACCESSIBILITY_TORCH_LIGHT, feedback_torchon_cb, NULL);
}

static void led_exit(void)
{
	int ret;

	ret = led_stop_pattern();
	if (ret < 0)
		_E("failed to stop playing led pattern");

	/* remove watch */
	vconf_ignore_key_changed(VCONFKEY_SETAPPL_ACCESSIBILITY_LED_NOTIFY, feedback_ledstatus_cb);
	vconf_ignore_key_changed(VCONFKEY_SETAPPL_ACCESSIBILITY_TORCH_LIGHT, feedback_torchon_cb);
}

static int led_play(feedback_pattern_e pattern)
{
	struct stat buf;
	int ret;

	if (ledstatus == 0) {
		_D("LED condition is OFF (ledstatus : %d)", ledstatus);
		return 0;
	}

	if (callstatus != VCONFKEY_CALL_OFF && !alert_callstatus) {
		_D("alert on call condition is OFF (alert_callstatus : %d)", alert_callstatus);
		return 0;
	}

	if (led_file[pattern] == NULL) {
		_D("This case(%s) does not play ledplayer", str_pattern[pattern]);
		return 0;
	}

	if (stat(led_file[pattern], &buf)) {
		_E("%s is not presents", led_file[pattern]);
		ret = restore_default_file(pattern);
		if (ret < 0) {
			_E("feedback_restore_default_file(%s) error", str_pattern[pattern]);
			return -EPERM;
		}
		_D("%s is restored", led_file[pattern]);
	}

	/* assistive light on */
	if (torchon == 1) {
		_D("torchlight on");
		if (led_set_brt(0) < 0) {
			_E("led_set_brt error");
			return -EPERM;
		}
		usleep(500000);
	}

	/* play led */
	ret = led_play_pattern(led_file[pattern], ITERATION_ONCE);
	if (ret < 0) {
		_E("failed to play led pattern(%s)", led_file[pattern]);
		return -EPERM;
	}

	return 0;
}

static int led_get_path(feedback_pattern_e pattern, char *buf, unsigned int buflen)
{
	const char *cur_path;
	int retry = FEEDBACK_RETRY_CNT;

	if (!buf || buflen <= 0)
		return -EINVAL;

	cur_path = led_file[pattern];
	if (!cur_path) {
		_E("This pattern(%s) in led type is not supported to play", str_pattern[pattern]);
		snprintf(buf, buflen, "NULL");
		return -ENOENT;
	}

	do {
		if(readlink(cur_path, buf, buflen) < 0) {
			_E("readlink is failed : %s", strerror(errno));
			return -EPERM;
		}
	} while(retry--);

	return 0;
}

static int led_set_path(feedback_pattern_e pattern, char *path)
{
	const char *cur_path;
	int ret;

	if (!path)
		return -EINVAL;

	cur_path = led_file[pattern];
	if (!cur_path) {
		_E("This pattern(%s) in led type is not supported to play", str_pattern[pattern]);
		return -ENOENT;
	}

	ret = change_symlink(cur_path, path);
	if (ret < 0) {
		_E("change_symlink is failed");
		return -EPERM;
	}

	return 0;
}

static const struct device_ops led_device_ops = {
	.type = FEEDBACK_TYPE_LED,
	.init = led_init,
	.exit = led_exit,
	.play = led_play,
	.get_path = led_get_path,
	.set_path = led_set_path,
};

DEVICE_OPS_REGISTER(&led_device_ops);
