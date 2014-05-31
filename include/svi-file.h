/*
 *  libsvi
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Jiyoung Yun <jy910.yun@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __SVI_FILE_H__
#define __SVI_FILE_H__

#define SVI_DATA_DIR "/opt/share/svi/"
#define SVI_ORIGIN_DATA_DIR "/usr/share/svi/"

#define SVI_SOUND_DIR SVI_DATA_DIR"sound/"
#define SVI_SOUND_TOUCH_DIR SVI_SOUND_DIR"touch/"
#define SVI_SOUND_OPER_DIR SVI_SOUND_DIR"operation/"

#define SVI_HAPTIC_DIR SVI_DATA_DIR"haptic/"
#define SVI_HAPTIC_TOUCH_DIR SVI_HAPTIC_DIR"touch/"
#define SVI_HAPTIC_OPER_DIR SVI_HAPTIC_DIR"operation/"
#define SVI_HAPTIC_NOTI_DIR SVI_HAPTIC_DIR"notification/"

#define SVI_LED_DIR SVI_DATA_DIR"led/"
#define SVI_LED_TOUCH_DIR SVI_LED_DIR"touch/"
#define SVI_LED_OPER_DIR SVI_LED_DIR"operation/"
#define SVI_LED_NOTI_DIR SVI_LED_DIR"notification/"

const char* snd_file[] = {
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : GENERAL */
	SVI_SOUND_TOUCH_DIR"touch1.wav",
	SVI_SOUND_TOUCH_DIR"touch2.wav",
	SVI_SOUND_TOUCH_DIR"touch3.wav",
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : TEXT_NUMERIC_INPUT */
	SVI_SOUND_TOUCH_DIR"sip.wav",
	SVI_SOUND_TOUCH_DIR"sip_backspace.wav",
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : DAILER */
	SVI_SOUND_TOUCH_DIR"key0.wav",
	SVI_SOUND_TOUCH_DIR"key1.wav",
	SVI_SOUND_TOUCH_DIR"key2.wav",
	SVI_SOUND_TOUCH_DIR"key3.wav",
	SVI_SOUND_TOUCH_DIR"key4.wav",
	SVI_SOUND_TOUCH_DIR"key5.wav",
	SVI_SOUND_TOUCH_DIR"key6.wav",
	SVI_SOUND_TOUCH_DIR"key7.wav",
	SVI_SOUND_TOUCH_DIR"key8.wav",
	SVI_SOUND_TOUCH_DIR"key9.wav",
	SVI_SOUND_TOUCH_DIR"keyasterisk.wav",
	SVI_SOUND_TOUCH_DIR"keysharp.wav",
	/* TOUCH : H/W OR SOFT TOUCH : HOLD(TAP & HOLD) */
	SVI_SOUND_TOUCH_DIR"hold.wav",
	/* TOUCH : H/W OR SOFT TOUCH : MULTI TAP */
	SVI_SOUND_TOUCH_DIR"multi_tap.wav",
	/* TOUCH : H/W OR SOFT TOUCH : TAP */
	SVI_SOUND_TOUCH_DIR"hw_tap.wav",
	/* TOUCH : H/W OR SOFT TOUCH : TAP & HOLD */
	SVI_SOUND_TOUCH_DIR"hw_hold.wav",

	/* OPERATION : POWER ON/OFF */
	SVI_SOUND_OPER_DIR"power_on.wav",
	SVI_SOUND_OPER_DIR"power_off.wav",
	/* OPERATION : CHARGECONN */
	SVI_SOUND_OPER_DIR"charger_connection.wav",
	/* OPERATION : FULLCHAREGED */
	SVI_SOUND_OPER_DIR"fully_charged.wav",
	/* OPERATION : LOW BATTERY */
	SVI_SOUND_OPER_DIR"low_battery.wav",
	/* OPERATION : LOCK/UNLOCK */
	SVI_SOUND_OPER_DIR"lock.wav",
	SVI_SOUND_OPER_DIR"unlock.wav",
	SVI_SOUND_OPER_DIR"lock_swipe.wav",
	SVI_SOUND_OPER_DIR"unlock_swipe.wav",
	/* OPERATION : CALL CONNECT/ DISCONNECT */
	SVI_SOUND_OPER_DIR"call_connect.wav",
	SVI_SOUND_OPER_DIR"call_disconnect.wav",
	/* OPERATION : MINUTE MINDER */
	SVI_SOUND_OPER_DIR"minute_minder.wav",
	/* OPERATION : VIBRATION */
	SVI_SOUND_OPER_DIR"vibration.wav",
	/* OPERATION : BALLOON MESSAGE SEND/RECV */
	SVI_SOUND_OPER_DIR"new_chat.wav",
	SVI_SOUND_OPER_DIR"sent_chat.wav",
	/* OPERATION : ON/OFF SLIDER */
	SVI_SOUND_OPER_DIR"on_off_slider.wav",
	/* OPERATION : CAMERA SHUTTER / SCREEN CAPTURE */
	SVI_SOUND_OPER_DIR"shutter.wav",
	/* OPERATION : LIST RE-ORDER */
	SVI_SOUND_OPER_DIR"list_reorder.wav",
	/* OPERATION : LIST SLIDER */
	SVI_SOUND_OPER_DIR"slider_sweep.wav"
};

/* led_file and haptic_file should be managed in the same order */
const char* haptic_file[] = {
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : GENERAL */
	SVI_HAPTIC_TOUCH_DIR"touch.ivt",
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : TEXT_NUMERIC_INPUT */
	SVI_HAPTIC_TOUCH_DIR"sip.ivt",
	SVI_HAPTIC_TOUCH_DIR"sip_backspace.ivt",
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : DAILER */
	SVI_HAPTIC_TOUCH_DIR"key0.ivt",
	SVI_HAPTIC_TOUCH_DIR"key1.ivt",
	SVI_HAPTIC_TOUCH_DIR"key2.ivt",
	SVI_HAPTIC_TOUCH_DIR"key3.ivt",
	SVI_HAPTIC_TOUCH_DIR"key4.ivt",
	SVI_HAPTIC_TOUCH_DIR"key5.ivt",
	SVI_HAPTIC_TOUCH_DIR"key6.ivt",
	SVI_HAPTIC_TOUCH_DIR"key7.ivt",
	SVI_HAPTIC_TOUCH_DIR"key8.ivt",
	SVI_HAPTIC_TOUCH_DIR"key9.ivt",
	SVI_HAPTIC_TOUCH_DIR"keyasterisk.ivt",
	SVI_HAPTIC_TOUCH_DIR"keysharp.ivt",
	/* TOUCH : H/W OR SOFT TOUCH : HOLD(TAP & HOLD) */
	SVI_HAPTIC_TOUCH_DIR"hold.ivt",
	/* TOUCH : H/W OR SOFT TOUCH : MULTI TAP */
	SVI_HAPTIC_TOUCH_DIR"multi_tap.ivt",
	/* TOUCH : H/W OR SOFT TOUCH : TAP */
	SVI_HAPTIC_TOUCH_DIR"hw_tap.ivt",
	/* TOUCH : H/W OR SOFT TOUCH : TAP & HOLD */
	SVI_HAPTIC_TOUCH_DIR"hw_hold.ivt",

	/* NOTIFICATION : INCOMING : CALL */
	SVI_HAPTIC_NOTI_DIR"incoming_call1.ivt",
	SVI_HAPTIC_NOTI_DIR"incoming_call2.ivt",
	SVI_HAPTIC_NOTI_DIR"incoming_call3.ivt",
	SVI_HAPTIC_NOTI_DIR"incoming_call4.ivt",
	SVI_HAPTIC_NOTI_DIR"incoming_call5.ivt",
	SVI_HAPTIC_NOTI_DIR"incoming_call6.ivt",
	/* NOTIFICATION : INCOMING : MESSAGE */
	SVI_HAPTIC_NOTI_DIR"message.ivt",
	/* NOTIFICATION : INCOMING : EMAIL */
	SVI_HAPTIC_NOTI_DIR"email.ivt",
	/* NOTIFICATION : ALARM : WAKEUP */
	SVI_HAPTIC_NOTI_DIR"wakeup.ivt",
	/* NOTIFICATION : ALARM : SCHEDULE */
	SVI_HAPTIC_NOTI_DIR"schedule.ivt",
	/* NOTIFICATION : ALARM : TIMER */
	SVI_HAPTIC_NOTI_DIR"timer.ivt",
	/* NOTIFICATION : GENERAL(TICKER/IM/SMS ETC) */
	SVI_HAPTIC_NOTI_DIR"general.ivt",

	/* OPERATION : POWER ON/OFF */
	SVI_HAPTIC_OPER_DIR"power_on.ivt",
	SVI_HAPTIC_OPER_DIR"power_off.ivt",
	/* OPERATION : CHARGECONN */
	SVI_HAPTIC_OPER_DIR"charger_connection.ivt",
	/* OPERATION : FULLCHAREGED */
	SVI_HAPTIC_OPER_DIR"fully_charged.ivt",
	/* OPERATION : LOW BATTERY */
	SVI_HAPTIC_OPER_DIR"low_battery.ivt",
	/* OPERATION : LOCK/UNLOCK */
	SVI_HAPTIC_OPER_DIR"lock.ivt",
	SVI_HAPTIC_OPER_DIR"unlock.ivt",
	SVI_HAPTIC_OPER_DIR"lock_swipe.ivt",
	SVI_HAPTIC_OPER_DIR"unlock_swipe.ivt",
	/* OPERATION : CALL CONNECT/ DISCONNECT */
	SVI_HAPTIC_OPER_DIR"call_connect.ivt",
	SVI_HAPTIC_OPER_DIR"call_disconnect.ivt",
	/* OPERATION : MINUTE MINDER */
	SVI_HAPTIC_OPER_DIR"minute_minder.ivt",
	/* OPERATION : VIBRATION */
	SVI_HAPTIC_OPER_DIR"vibration.ivt",
	/* OPERATION : BALLOON MESSAGE SEND/RECV */
	SVI_HAPTIC_OPER_DIR"new_chat.ivt",
	SVI_HAPTIC_OPER_DIR"sent_chat.ivt",
	/* OPERATION : ON/OFF SLIDER */
	SVI_HAPTIC_OPER_DIR"on_off_slider.ivt",
	/* OPERATION : CAMERA SHUTTER / SCREEN CAPTURE */
	SVI_HAPTIC_OPER_DIR"shutter.ivt",
	/* OPERATION : LIST RE-ORDER */
	SVI_HAPTIC_OPER_DIR"list_reorder.ivt",
	/* OPERATION : LIST SLIDER */
	SVI_HAPTIC_OPER_DIR"slider_sweep.ivt"
};

/* led_file and haptic_file should be managed in the same order */
const char* led_file[] = {
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : GENERAL */
	SVI_LED_TOUCH_DIR"touch.led",
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : TEXT_NUMERIC_INPUT */
	SVI_LED_TOUCH_DIR"sip.led",
	SVI_LED_TOUCH_DIR"sip_backspace.led",
	/* TOUCH : SCREEN TOUCH : TAP(TOUCH & RELEASE) : DAILER */
	SVI_LED_TOUCH_DIR"key0.led",
	SVI_LED_TOUCH_DIR"key1.led",
	SVI_LED_TOUCH_DIR"key2.led",
	SVI_LED_TOUCH_DIR"key3.led",
	SVI_LED_TOUCH_DIR"key4.led",
	SVI_LED_TOUCH_DIR"key5.led",
	SVI_LED_TOUCH_DIR"key6.led",
	SVI_LED_TOUCH_DIR"key7.led",
	SVI_LED_TOUCH_DIR"key8.led",
	SVI_LED_TOUCH_DIR"key9.led",
	SVI_LED_TOUCH_DIR"keyasterisk.led",
	SVI_LED_TOUCH_DIR"keysharp.led",
	/* TOUCH : H/W OR SOFT TOUCH : HOLD(TAP & HOLD) */
	SVI_LED_TOUCH_DIR"hold.led",
	/* TOUCH : H/W OR SOFT TOUCH : MULTI TAP */
	SVI_LED_TOUCH_DIR"multi_tap.led",
	/* TOUCH : H/W OR SOFT TOUCH : TAP */
	SVI_LED_TOUCH_DIR"hw_tap.led",
	/* TOUCH : H/W OR SOFT TOUCH : TAP & HOLD */
	SVI_LED_TOUCH_DIR"hw_hold.led",

	/* NOTIFICATION : INCOMING : CALL */
	SVI_LED_NOTI_DIR"incoming_call1.led",
	SVI_LED_NOTI_DIR"incoming_call2.led",
	SVI_LED_NOTI_DIR"incoming_call3.led",
	SVI_LED_NOTI_DIR"incoming_call4.led",
	SVI_LED_NOTI_DIR"incoming_call5.led",
	SVI_LED_NOTI_DIR"incoming_call6.led",
	/* NOTIFICATION : INCOMING : MESSAGE */
	SVI_LED_NOTI_DIR"message.led",
	/* NOTIFICATION : INCOMING : EMAIL */
	SVI_LED_NOTI_DIR"email.led",
	/* NOTIFICATION : ALARM : WAKEUP */
	SVI_LED_NOTI_DIR"wakeup.led",
	/* NOTIFICATION : ALARM : SCHEDULE */
	SVI_LED_NOTI_DIR"schedule.led",
	/* NOTIFICATION : ALARM : TIMER */
	SVI_LED_NOTI_DIR"timer.led",
	/* NOTIFICATION : GENERAL(TICKER/IM/SMS ETC) */
	SVI_LED_NOTI_DIR"general.led",

	/* OPERATION : POWER ON/OFF */
	SVI_LED_OPER_DIR"power_on.led",
	SVI_LED_OPER_DIR"power_off.led",
	/* OPERATION : CHARGECONN */
	SVI_LED_OPER_DIR"charger_connection.led",
	/* OPERATION : FULLCHAREGED */
	SVI_LED_OPER_DIR"fully_charged.led",
	/* OPERATION : LOW BATTERY */
	SVI_LED_OPER_DIR"low_battery.led",
	/* OPERATION : LOCK/UNLOCK */
	SVI_LED_OPER_DIR"lock.led",
	SVI_LED_OPER_DIR"unlock.led",
	SVI_LED_OPER_DIR"lock_swipe.led",
	SVI_LED_OPER_DIR"unlock_swipe.led",
	/* OPERATION : CALL CONNECT/ DISCONNECT */
	SVI_LED_OPER_DIR"call_connect.led",
	SVI_LED_OPER_DIR"call_disconnect.led",
	/* OPERATION : MINUTE MINDER */
	SVI_LED_OPER_DIR"minute_minder.led",
	/* OPERATION : VIBRATION */
	SVI_LED_OPER_DIR"vibration.led",
	/* OPERATION : BALLOON MESSAGE SEND/RECV */
	SVI_LED_OPER_DIR"new_chat.led",
	SVI_LED_OPER_DIR"sent_chat.led",
	/* OPERATION : ON/OFF SLIDER */
	SVI_LED_OPER_DIR"on_off_slider.led",
	/* OPERATION : CAMERA SHUTTER / SCREEN CAPTURE */
	SVI_LED_OPER_DIR"shutter.led",
	/* OPERATION : LIST RE-ORDER */
	SVI_LED_OPER_DIR"list_reorder.led",
	/* OPERATION : LIST SLIDER */
	SVI_LED_OPER_DIR"slider_sweep.led"
};

#endif //__SVI_FILE_H__
