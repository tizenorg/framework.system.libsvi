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


#ifndef __FEEDBACK_IDS_H__
#define __FEEDBACK_IDS_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file feedback-ids.h
 * @brief This file contains the feedback API
 */

/**
 * @addtogroup FEEDBACK
 * @{
 */

/**
 * @brief Enumerations of the type for feedback interface
 * @details
 *
 */
typedef enum
{
	FEEDBACK_TYPE_NONE,
	FEEDBACK_TYPE_SOUND,
	FEEDBACK_TYPE_VIBRATION,
	FEEDBACK_TYPE_END
} feedback_type_e;

/**
 * @brief Enumerations of the system pre-defined patterns for feedback interface
 * @details
 * Each feedback pattern can have separate media files of each types.
 * But Depending on vendor design, pattern may not have any type of file.
 *
 */
typedef enum
{
	FEEDBACK_PATTERN_NONE = -1,

	FEEDBACK_PATTERN_TAP = 0,      			/**< feedback pattern when general touch */
	FEEDBACK_PATTERN_SIP,          			/**< feedback pattern when touch text key */
	FEEDBACK_PATTERN_SIP_BACKSPACE,			/**< feedback pattern when touch backspace key */
	FEEDBACK_PATTERN_MAX_CHARACTER,			/**< feedback pattern when max character */
	FEEDBACK_PATTERN_KEY0,         			/**< feedback pattern when touch numeric 0 key */
	FEEDBACK_PATTERN_KEY1,         			/**< feedback pattern when touch numeric 1 key */
	FEEDBACK_PATTERN_KEY2,         			/**< feedback pattern when touch numeric 2 key */
	FEEDBACK_PATTERN_KEY3,         			/**< feedback pattern when touch numeric 3 key */
	FEEDBACK_PATTERN_KEY4,         			/**< feedback pattern when touch numeric 4 key */
	FEEDBACK_PATTERN_KEY5,         			/**< feedback pattern when touch numeric 5 key */
	FEEDBACK_PATTERN_KEY6,         			/**< feedback pattern when touch numeric 6 key */
	FEEDBACK_PATTERN_KEY7,         			/**< feedback pattern when touch numeric 7 key */
	FEEDBACK_PATTERN_KEY8,         			/**< feedback pattern when touch numeric 8 key */
	FEEDBACK_PATTERN_KEY9,         			/**< feedback pattern when touch numeric 9 key */
	FEEDBACK_PATTERN_KEY_STAR,     			/**< feedback pattern when touch star key */
	FEEDBACK_PATTERN_KEY_SHARP,    			/**< feedback pattern when touch sharp key */
	FEEDBACK_PATTERN_HOLD,         			/**< feedback pattern when touch hold */
	FEEDBACK_PATTERN_MULTI_TAP,    			/**< feedback pattern when multi touch */
	FEEDBACK_PATTERN_HW_TAP,       			/**< feedback pattern when press hardware key */
	FEEDBACK_PATTERN_HW_HOLD,      			/**< feedback pattern when holding press hardware key */

	FEEDBACK_PATTERN_MESSAGE,         		/**< feedback pattern when incoming a message */
	FEEDBACK_PATTERN_MESSAGE_ON_CALL, 		/**< feedback pattern when incoming a message on call */
	FEEDBACK_PATTERN_EMAIL,           		/**< feedback pattern when incoming an email */
	FEEDBACK_PATTERN_EMAIL_ON_CALL,   		/**< feedback pattern when incoming an email on call */
	FEEDBACK_PATTERN_WAKEUP,          		/**< feedback pattern when alert wake up call */
	FEEDBACK_PATTERN_WAKEUP_ON_CALL,  		/**< feedback pattern when alert wake up call on call */
	FEEDBACK_PATTERN_SCHEDULE,        		/**< feedback pattern when alert schedule alarm */
	FEEDBACK_PATTERN_SCHEDULE_ON_CALL,		/**< feedback pattern when alert schedule alarm on call */
	FEEDBACK_PATTERN_TIMER,           		/**< feedback pattern when alert timer */
	FEEDBACK_PATTERN_TIMER_ON_CALL,   		/**< feedback pattern when alert timer on call */
	FEEDBACK_PATTERN_GENERAL,         		/**< feedback pattern when alert general event */
	FEEDBACK_PATTERN_GENERAL_ON_CALL, 		/**< feedback pattern when alert general event on call */

	FEEDBACK_PATTERN_POWERON,            	/**< feedback pattern when power on */
	FEEDBACK_PATTERN_POWEROFF,           	/**< feedback pattern when power off */
	FEEDBACK_PATTERN_CHARGERCONN,        	/**< feedback pattern when connecting charger */
	FEEDBACK_PATTERN_CHARGERCONN_ON_CALL,	/**< feedback pattern when connecting charger on call */
	FEEDBACK_PATTERN_FULLCHARGED,        	/**< feedback pattern when full charged */
	FEEDBACK_PATTERN_FULLCHARGED_ON_CALL,	/**< feedback pattern when full charged on call */
	FEEDBACK_PATTERN_LOWBATT,            	/**< feedback pattern when low battery */
	FEEDBACK_PATTERN_LOWBATT_ON_CALL,    	/**< feedback pattern when low battery on call */
	FEEDBACK_PATTERN_LOCK,               	/**< feedback pattern when lock */
	FEEDBACK_PATTERN_UNLOCK,             	/**< feedback pattern when unlock */
	FEEDBACK_PATTERN_CALLCONNECT,        	/**< feedback pattern when connecting call */
	FEEDBACK_PATTERN_DISCALLCONNECT,     	/**< feedback pattern when disconnecting call */
	FEEDBACK_PATTERN_MINUTEMINDER,       	/**< feedback pattern when minute minder */
	FEEDBACK_PATTERN_VIBRATION,          	/**< feedback pattern when vibration */
	FEEDBACK_PATTERN_SHUTTER,            	/**< feedback pattern when screen capture or camera shutter */
	FEEDBACK_PATTERN_LIST_REORDER,       	/**< feedback pattern when list reorder */
	FEEDBACK_PATTERN_SLIDER_SWEEP,       	/**< feedback pattern when slider sweep */
	FEEDBACK_PATTERN_VOLUME_KEY,         	/**< feedback pattern when pressed volume key */

	FEEDBACK_PATTERN_END,

	/* START : Will be removed */
	FEEDBACK_PATTERN_TOUCH_TAP = FEEDBACK_PATTERN_TAP,
	FEEDBACK_PATTERN_TOUCH_MULTI_TAP = FEEDBACK_PATTERN_MULTI_TAP,
	FEEDBACK_PATTERN_TOUCH_KEY = FEEDBACK_PATTERN_KEY0,
	FEEDBACK_PATTERN_TOUCH_HOLD = FEEDBACK_PATTERN_HOLD,
	/* END : Will be removed */

} feedback_pattern_e;

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif //__FEEDBACK_IDS_H__
