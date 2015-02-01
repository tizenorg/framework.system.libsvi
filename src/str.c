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

const char *str_type[] =
{
	"FEEDBACK_TYPE_NONE",
	"FEEDBACK_TYPE_SOUND",
	"FEEDBACK_TYPE_VIBRATION",
	"FEEDBACK_TYPE_LED",
	"FEEDBACK_TYPE_END",
};

const char *str_pattern[] =
{
	"FEEDBACK_PATTERN_TAP",
	"FEEDBACK_PATTERN_SIP",
	"FEEDBACK_PATTERN_SIP_BACKSPACE",
	"FEEDBACK_PATTERN_SIP_FUNCTION",
	"FEEDBACK_PATTERN_SIP_FJKEY",
	"FEEDBACK_PATTERN_MAX_CHARACTER",
	"FEEDBACK_PATTERN_KEY0",
	"FEEDBACK_PATTERN_KEY1",
	"FEEDBACK_PATTERN_KEY2",
	"FEEDBACK_PATTERN_KEY3",
	"FEEDBACK_PATTERN_KEY4",
	"FEEDBACK_PATTERN_KEY5",
	"FEEDBACK_PATTERN_KEY6",
	"FEEDBACK_PATTERN_KEY7",
	"FEEDBACK_PATTERN_KEY8",
	"FEEDBACK_PATTERN_KEY9",
	"FEEDBACK_PATTERN_KEY_STAR",
	"FEEDBACK_PATTERN_KEY_SHARP",
	"FEEDBACK_PATTERN_KEY_BACK",
	"FEEDBACK_PATTERN_HOLD",
	"FEEDBACK_PATTERN_MULTI_TAP",
	"FEEDBACK_PATTERN_HW_TAP",
	"FEEDBACK_PATTERN_HW_HOLD",

	"FEEDBACK_PATTERN_MESSAGE",
	"FEEDBACK_PATTERN_MESSAGE_ON_CALL",
	"FEEDBACK_PATTERN_EMAIL",
	"FEEDBACK_PATTERN_EMAIL_ON_CALL",
	"FEEDBACK_PATTERN_WAKEUP",
	"FEEDBACK_PATTERN_WAKEUP_ON_CALL",
	"FEEDBACK_PATTERN_SCHEDULE",
	"FEEDBACK_PATTERN_SCHEDULE_ON_CALL",
	"FEEDBACK_PATTERN_TIMER",
	"FEEDBACK_PATTERN_TIMER_ON_CALL",
	"FEEDBACK_PATTERN_GENERAL",
	"FEEDBACK_PATTERN_GENERAL_ON_CALL",
	"FEEDBACK_PATTERN_SMART_ALERT",

	"FEEDBACK_PATTERN_POWERON",
	"FEEDBACK_PATTERN_POWEROFF",
	"FEEDBACK_PATTERN_CHARGERCONN",
	"FEEDBACK_PATTERN_CHARGERCONN_ON_CALL",
	"FEEDBACK_PATTERN_CHARGING_ERROR",
	"FEEDBACK_PATTERN_CHARGING_ERROR_ON_CALL",
	"FEEDBACK_PATTERN_FULLCHARGED",
	"FEEDBACK_PATTERN_FULLCHARGED_ON_CALL",
	"FEEDBACK_PATTERN_LOWBATT",
	"FEEDBACK_PATTERN_LOWBATT_ON_CALL",
	"FEEDBACK_PATTERN_LOCK",
	"FEEDBACK_PATTERN_UNLOCK",
	"FEEDBACK_PATTERN_LOCK_SWIPE",
	"FEEDBACK_PATTERN_UNLOCK_SWIPE",
	"FEEDBACK_PATTERN_GEOMETRIC_LOCK",
	"FEEDBACK_PATTERN_CALLCONNECT",
	"FEEDBACK_PATTERN_DISCALLCONNECT",
	"FEEDBACK_PATTERN_OUTGOING_CALL",
	"FEEDBACK_PATTERN_MINUTEMINDER",
	"FEEDBACK_PATTERN_VIBRATION_ON",
	"FEEDBACK_PATTERN_SILENT_OFF",
	"FEEDBACK_PATTERN_BT_CONNECTED",
	"FEEDBACK_PATTERN_BT_DISCONNECTED",
	"FEEDBACK_PATTERN_BT_PAIRING",
	"FEEDBACK_PATTERN_BT_WAITING",
	"FEEDBACK_PATTERN_SCREEN_CAPTURE",
	"FEEDBACK_PATTERN_LIST_REORDER",
	"FEEDBACK_PATTERN_LIST_SLIDER",
	"FEEDBACK_PATTERN_VOLUME_KEY",
	"FEEDBACK_PATTERN_MMS",
	"FEEDBACK_PATTERN_HOURLY_ALERT",

	"FEEDBACK_PATTERN_SAFETY_ALERT",
	"FEEDBACK_PATTERN_ACCIDENT_DETECT",
	"FEEDBACK_PATTERN_SEND_SOS_MESSAGE",
	"FEEDBACK_PATTERN_END_SOS_MESSAGE",
	"FEEDBACK_PATTERN_EMERGENCY_BUZZER",
	"FEEDBACK_PATTERN_SAFETY_LOW_POWER",
	"FEEDBACK_PATTERN_CMAS",
	"FEEDBACK_PATTERN_SPEED_UP",
	"FEEDBACK_PATTERN_SLOW_DOWN",
	"FEEDBACK_PATTERN_KEEP_THIS_PACE",
	"FEEDBACK_PATTERN_GOAL_ACHIEVED",
	"FEEDBACK_PATTERN_EXERCISE_COUNT",
	"FEEDBACK_PATTERN_START_CUE",
	"FEEDBACK_PATTERN_HEALTH_PACE",
	"FEEDBACK_PATTERN_INACTIVE_TIME",
	"FEEDBACK_PATTERN_MEASURING_SUCCESS",
	"FEEDBACK_PATTERN_MEASURING_FAILURE",
	"FEEDBACK_PATTERN_UV_PROCESSING",
	"FEEDBACK_PATTERN_SHEALTH_START",
	"FEEDBACK_PATTERN_SHEALTH_PAUSE",
	"FEEDBACK_PATTERN_SHEALTH_STOP",
	"FEEDBACK_PATTERN_3RD_APPLICATION",
};
