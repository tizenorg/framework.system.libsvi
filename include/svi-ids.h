/*
 *  libsvi
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Seokkyu Jang <seokkyu.jang@samsung.com>
 * Contact: Sangil Yoon <si83.yoon@samsung.com>
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

#ifndef __SVI_IDS_H__
#define __SVI_IDS_H__


typedef enum sound_type_t {
    SVI_SND_NONE = -1,

    SVI_SND_TOUCH_TOUCH1 = 0,
    SVI_SND_TOUCH_TOUCH2,
    SVI_SND_TOUCH_TOUCH3,
    SVI_SND_TOUCH_SIP,
    SVI_SND_TOUCH_HOLD,
    SVI_SND_TOUCH_MULTI_TAP,
    SVI_SND_TOUCH_HW_TAP,
    SVI_SND_TOUCH_HW_HOLD,

    SVI_SND_TOUCH_KEY00,
    SVI_SND_TOUCH_KEY01,
    SVI_SND_TOUCH_KEY02,
    SVI_SND_TOUCH_KEY03,
    SVI_SND_TOUCH_KEY04,
    SVI_SND_TOUCH_KEY05,
    SVI_SND_TOUCH_KEY06,
    SVI_SND_TOUCH_KEY07,
    SVI_SND_TOUCH_KEY08,
    SVI_SND_TOUCH_KEY09,
    SVI_SND_TOUCH_KEY_STAR,
    SVI_SND_TOUCH_KEY_SHARP,

    SVI_SND_OPERATION_POWERON,
    SVI_SND_OPERATION_POWEROFF,
    SVI_SND_OPERATION_CHARGERCONN,
    SVI_SND_OPERATION_FULLCHARGED,
    SVI_SND_OPERATION_LOWBATT,
    SVI_SND_OPERATION_LOCK,
    SVI_SND_OPERATION_UNLOCK,
    SVI_SND_OPERATION_CALLCONN,
    SVI_SND_OPERATION_CALLDISCONN,
    SVI_SND_OPERATION_MINUTE_MINDER,
    SVI_SND_OPERATION_VIBRATION,
    SVI_SND_OPERATION_NEWCHAT,
    SVI_SND_OPERATION_SENTCHAT,
    SVI_SND_OPERATION_ONOFFSLIDER,
    SVI_SND_OPERATION_SCRCAPTURE,
	
    SVI_SND_ENUM_END = 100

} sound_type;

typedef enum vibration_type_t {
	SVI_VIB_NONE = -1,

	SVI_VIB_TOUCH_TOUCH = 0,
	SVI_VIB_TOUCH_SIP,
	SVI_VIB_TOUCH_HOLD,
	SVI_VIB_TOUCH_MULTI_TAP,
	SVI_VIB_TOUCH_HW_TAP,
	SVI_VIB_TOUCH_HW_HOLD,

	SVI_VIB_TOUCH_KEY00,
	SVI_VIB_TOUCH_KEY01,
	SVI_VIB_TOUCH_KEY02,
	SVI_VIB_TOUCH_KEY03,
	SVI_VIB_TOUCH_KEY04,
	SVI_VIB_TOUCH_KEY05,
	SVI_VIB_TOUCH_KEY06,
	SVI_VIB_TOUCH_KEY07,
	SVI_VIB_TOUCH_KEY08,
	SVI_VIB_TOUCH_KEY09,
	SVI_VIB_TOUCH_KEY_STAR,
	SVI_VIB_TOUCH_KEY_SHARP,

	SVI_VIB_NOTIFICATION_INCOMING_CALL01,
	SVI_VIB_NOTIFICATION_INCOMING_CALL02,
	SVI_VIB_NOTIFICATION_INCOMING_CALL03,
	SVI_VIB_NOTIFICATION_MESSAGE,
	SVI_VIB_NOTIFICATION_EMAIL,
	SVI_VIB_NOTIFICATION_WAKEUP,
	SVI_VIB_NOTIFICATION_SCHEDULE,
	SVI_VIB_NOTIFICATION_TIMER,
	SVI_VIB_NOTIFICATION_GENERAL,
    
	SVI_VIB_OPERATION_POWER_ON,
	SVI_VIB_OPERATION_POWER_OFF,
	SVI_VIB_OPERATION_CHARGERCONN,
	SVI_VIB_OPERATION_FULLYCHARGED,
	SVI_VIB_OPERATION_LOTBATT,
	SVI_VIB_OPERATION_LOCK,
	SVI_VIB_OPERATION_UNLOCK,
	SVI_VIB_OPERATION_CALLCONNECT,
	SVI_VIB_OPERATION_DISCALLCONNECT,
	SVI_VIB_OPERATION_MINUTEMINDER,
	SVI_VIB_OPERATION_VIBRATION,
	SVI_VIB_OPERATION_NEWCHAT,
	SVI_VIB_OPERATION_SENDCHAT,
	SVI_VIB_OPERATION_ONOFFSLIDER,
	SVI_VIB_OPERATION_SHUTTER,

	SVI_VIB_ENUM_END = 100

} vibration_type;

#endif //__SVI_IDS_H__
