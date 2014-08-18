/* Copyright (c) 2013 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/**@file
 *
 * @defgroup ant_stack_handler_types Types definitions for ANT support in SoftDevice handler.
 * @{
 * @ingroup  app_common
 * @brief    This file contains the declarations of types required for ANT stack support. These
 *           types will be defined when the preprocessor define ANT_STACK_SUPPORT_REQD is defined.
 */

#ifndef ANT_STACK_HANDLER_DEFINES_H__
#define ANT_STACK_HANDLER_DEFINES_H__

#ifdef ANT_STACK_SUPPORT_REQD

#include <stdlib.h>

// todo: use a macro defined in ant stack instead of ANT_STACK_EVT_MSG_BUF_SIZE
#define ANT_STACK_EVT_MSG_BUF_SIZE      32                                                /**< Size of ANT event message buffer. This will be provided to the SoftDevice while fetching an event. */
#define ANT_STACK_EVT_STRUCT_SIZE       (sizeof(ant_evt_t))                               /**< Size of the @ref ant_evt_t structure. This will be used by the @ref softdevice_handler.h to internal event buffer size needed. */

/**@brief ANT stack event type. */
typedef struct
{
    uint8_t channel;                                                                      /**< Channel number. */
    uint8_t event;                                                                        /**< Event code. */
    uint8_t evt_buffer[ANT_STACK_EVT_MSG_BUF_SIZE];                                       /**< Event message buffer. */
} ant_evt_t;

/**@brief Application ANT stack event handler type. */
typedef void (*ant_evt_handler_t) (ant_evt_t * p_ant_evt);

/**@brief     Function for registering for ANT events.
 *
 * @details   The application should use this function to register for receiving ANT events from
 *            the SoftDevice. If the application does not call this function, then any ANT event
 *            that may be generated by the SoftDevice will NOT be fetched. Once the application has
 *            registered for the events, it is not possible to  possible to cancel the registration.
 *            However, it is possible to register a different function for handling the events at
 *            any point of time.
 *
 * @param[in] ant_evt_handler Function to be called for each received ANT event.
 *
 * @retval    NRF_SUCCESS     Successful registration.
 * @retval    NRF_ERROR_NULL  Null pointer provided as input.
 */
uint32_t softdevice_ant_evt_handler_set(ant_evt_handler_t ant_evt_handler);

#else

// The ANT Stack support is not required.

#define ANT_STACK_EVT_STRUCT_SIZE       0                                                 /**< Since the ANT stack support is not required, this is equated to 0, so that the @ref softdevice_handler.h can compute the internal event buffer size without having to care for ANT events.*/

#endif // ANT_STACK_SUPPORT_REQD

#endif // ANT_DEFINES_H__

/** @} */