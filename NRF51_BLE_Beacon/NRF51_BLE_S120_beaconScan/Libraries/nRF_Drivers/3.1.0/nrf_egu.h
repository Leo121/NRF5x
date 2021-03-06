/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
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

#ifndef NRF_EGU_H__
#define NRF_EGU_H__

#ifndef NRF52
    #error EGU is not supported on your chip.
#endif

/**
* @defgroup nrf_egu EGU (Event Generator Unit) abstraction
* @{
* @ingroup nrf_drivers
* @brief EGU (Event Generator Unit) module functions.
*
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "nrf_assert.h"
#include "nrf.h"

#define NRF_EGU_COUNT           6   /**< Number of EGU instances. */
#define NRF_EGU_CHANNEL_COUNT   16  /**< Number of channels per EGU instance. */

/**
 * @enum  nrf_egu_task_t
 * @brief EGU tasks.
 */
typedef enum
{
    /*lint -save -e30 -esym(628,__INTADDR__)*/
    NRF_EGU_TASK_TRIGGER0  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[0]),  /**< Trigger 0 for triggering the corresponding TRIGGERED[0] event. */
    NRF_EGU_TASK_TRIGGER1  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[1]),  /**< Trigger 1 for triggering the corresponding TRIGGERED[1] event. */
    NRF_EGU_TASK_TRIGGER2  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[2]),  /**< Trigger 2 for triggering the corresponding TRIGGERED[2] event. */
    NRF_EGU_TASK_TRIGGER3  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[3]),  /**< Trigger 3 for triggering the corresponding TRIGGERED[3] event. */
    NRF_EGU_TASK_TRIGGER4  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[4]),  /**< Trigger 4 for triggering the corresponding TRIGGERED[4] event. */
    NRF_EGU_TASK_TRIGGER5  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[5]),  /**< Trigger 5 for triggering the corresponding TRIGGERED[5] event. */
    NRF_EGU_TASK_TRIGGER6  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[6]),  /**< Trigger 6 for triggering the corresponding TRIGGERED[6] event. */
    NRF_EGU_TASK_TRIGGER7  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[7]),  /**< Trigger 7 for triggering the corresponding TRIGGERED[7] event. */
    NRF_EGU_TASK_TRIGGER8  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[8]),  /**< Trigger 8 for triggering the corresponding TRIGGERED[8] event. */
    NRF_EGU_TASK_TRIGGER9  = offsetof(NRF_EGU_Type, TASKS_TRIGGER[9]),  /**< Trigger 9 for triggering the corresponding TRIGGERED[9] event. */
    NRF_EGU_TASK_TRIGGER10 = offsetof(NRF_EGU_Type, TASKS_TRIGGER[10]), /**< Trigger 10 for triggering the corresponding TRIGGERED[10] event. */
    NRF_EGU_TASK_TRIGGER11 = offsetof(NRF_EGU_Type, TASKS_TRIGGER[11]), /**< Trigger 11 for triggering the corresponding TRIGGERED[11] event. */
    NRF_EGU_TASK_TRIGGER12 = offsetof(NRF_EGU_Type, TASKS_TRIGGER[12]), /**< Trigger 12 for triggering the corresponding TRIGGERED[12] event. */
    NRF_EGU_TASK_TRIGGER13 = offsetof(NRF_EGU_Type, TASKS_TRIGGER[13]), /**< Trigger 13 for triggering the corresponding TRIGGERED[13] event. */
    NRF_EGU_TASK_TRIGGER14 = offsetof(NRF_EGU_Type, TASKS_TRIGGER[14]), /**< Trigger 14 for triggering the corresponding TRIGGERED[14] event. */
    NRF_EGU_TASK_TRIGGER15 = offsetof(NRF_EGU_Type, TASKS_TRIGGER[15])  /**< Trigger 15 for triggering the corresponding TRIGGERED[15] event. */
    /*lint -restore*/
} nrf_egu_task_t;


/**
 * @enum  nrf_egu_event_t
 * @brief EGU events.
 */
typedef enum
{
    /*lint -save -e30 -esym(628,__INTADDR__)*/
    NRF_EGU_EVENT_TRIGGERED0  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[0]),  /**< Event number 0 generated by triggering the corresponding TRIGGER[0] task. */
    NRF_EGU_EVENT_TRIGGERED1  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[1]),  /**< Event number 1 generated by triggering the corresponding TRIGGER[1] task. */
    NRF_EGU_EVENT_TRIGGERED2  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[2]),  /**< Event number 2 generated by triggering the corresponding TRIGGER[2] task. */
    NRF_EGU_EVENT_TRIGGERED3  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[3]),  /**< Event number 3 generated by triggering the corresponding TRIGGER[3] task. */
    NRF_EGU_EVENT_TRIGGERED4  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[4]),  /**< Event number 4 generated by triggering the corresponding TRIGGER[4] task. */
    NRF_EGU_EVENT_TRIGGERED5  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[5]),  /**< Event number 5 generated by triggering the corresponding TRIGGER[5] task. */
    NRF_EGU_EVENT_TRIGGERED6  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[6]),  /**< Event number 6 generated by triggering the corresponding TRIGGER[6] task. */
    NRF_EGU_EVENT_TRIGGERED7  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[7]),  /**< Event number 7 generated by triggering the corresponding TRIGGER[7] task. */
    NRF_EGU_EVENT_TRIGGERED8  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[8]),  /**< Event number 8 generated by triggering the corresponding TRIGGER[8] task. */
    NRF_EGU_EVENT_TRIGGERED9  = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[9]),  /**< Event number 9 generated by triggering the corresponding TRIGGER[9] task. */
    NRF_EGU_EVENT_TRIGGERED10 = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[10]), /**< Event number 10 generated by triggering the corresponding TRIGGER[10] task. */
    NRF_EGU_EVENT_TRIGGERED11 = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[11]), /**< Event number 11 generated by triggering the corresponding TRIGGER[11] task. */
    NRF_EGU_EVENT_TRIGGERED12 = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[12]), /**< Event number 12 generated by triggering the corresponding TRIGGER[12] task. */
    NRF_EGU_EVENT_TRIGGERED13 = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[13]), /**< Event number 13 generated by triggering the corresponding TRIGGER[13] task. */
    NRF_EGU_EVENT_TRIGGERED14 = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[14]), /**< Event number 14 generated by triggering the corresponding TRIGGER[14] task. */
    NRF_EGU_EVENT_TRIGGERED15 = offsetof(NRF_EGU_Type, EVENTS_TRIGGERED[15])  /**< Event number 15 generated by triggering the corresponding TRIGGER[15] task. */
    /*lint -restore*/
} nrf_egu_event_t;


/**
 * @enum  nrf_egu_int_mask_t
 * @brief EGU interrupts.
 */
typedef enum
{
    NRF_EGU_INT_TRIGGERED0  = EGU_INTENSET_TRIGGERED0_Msk,  /**< Interrupt on EVENTS_TRIGGERED[0] event. */
    NRF_EGU_INT_TRIGGERED1  = EGU_INTENSET_TRIGGERED1_Msk,  /**< Interrupt on EVENTS_TRIGGERED[1] event. */
    NRF_EGU_INT_TRIGGERED2  = EGU_INTENSET_TRIGGERED2_Msk,  /**< Interrupt on EVENTS_TRIGGERED[2] event. */
    NRF_EGU_INT_TRIGGERED3  = EGU_INTENSET_TRIGGERED3_Msk,  /**< Interrupt on EVENTS_TRIGGERED[3] event. */
    NRF_EGU_INT_TRIGGERED4  = EGU_INTENSET_TRIGGERED4_Msk,  /**< Interrupt on EVENTS_TRIGGERED[4] event. */
    NRF_EGU_INT_TRIGGERED5  = EGU_INTENSET_TRIGGERED5_Msk,  /**< Interrupt on EVENTS_TRIGGERED[5] event. */
    NRF_EGU_INT_TRIGGERED6  = EGU_INTENSET_TRIGGERED6_Msk,  /**< Interrupt on EVENTS_TRIGGERED[6] event. */
    NRF_EGU_INT_TRIGGERED7  = EGU_INTENSET_TRIGGERED7_Msk,  /**< Interrupt on EVENTS_TRIGGERED[7] event. */
    NRF_EGU_INT_TRIGGERED8  = EGU_INTENSET_TRIGGERED8_Msk,  /**< Interrupt on EVENTS_TRIGGERED[8] event. */
    NRF_EGU_INT_TRIGGERED9  = EGU_INTENSET_TRIGGERED9_Msk,  /**< Interrupt on EVENTS_TRIGGERED[9] event. */
    NRF_EGU_INT_TRIGGERED10 = EGU_INTENSET_TRIGGERED10_Msk, /**< Interrupt on EVENTS_TRIGGERED[10] event. */
    NRF_EGU_INT_TRIGGERED11 = EGU_INTENSET_TRIGGERED11_Msk, /**< Interrupt on EVENTS_TRIGGERED[11] event. */
    NRF_EGU_INT_TRIGGERED12 = EGU_INTENSET_TRIGGERED12_Msk, /**< Interrupt on EVENTS_TRIGGERED[12] event. */
    NRF_EGU_INT_TRIGGERED13 = EGU_INTENSET_TRIGGERED13_Msk, /**< Interrupt on EVENTS_TRIGGERED[13] event. */
    NRF_EGU_INT_TRIGGERED14 = EGU_INTENSET_TRIGGERED14_Msk, /**< Interrupt on EVENTS_TRIGGERED[14] event. */
    NRF_EGU_INT_TRIGGERED15 = EGU_INTENSET_TRIGGERED15_Msk, /**< Interrupt on EVENTS_TRIGGERED[15] event. */
    NRF_EGU_INT_ALL         = 0xFFFFuL
} nrf_egu_int_mask_t;


/**
 * @brief Function for triggering a specific EGU task.
 *
 * @param NRF_EGUx EGU instance.
 * @param egu_task EGU task.
 */
__STATIC_INLINE void nrf_egu_task_trigger(NRF_EGU_Type * NRF_EGUx, nrf_egu_task_t egu_task)
{
    *((volatile uint32_t *)((uint8_t *)NRF_EGUx + (uint32_t)egu_task)) = 0x1UL;
}


/**
 * @brief Function for returning the address of a specific EGU task register.
 *
 * @param NRF_EGUx EGU instance.
 * @param egu_task EGU task.
 */
__STATIC_INLINE uint32_t * nrf_egu_task_address_get(NRF_EGU_Type * NRF_EGUx,
                                                    nrf_egu_task_t egu_task)
{
    return (uint32_t *)((uint8_t *)NRF_EGUx + (uint32_t)egu_task);
}


/**
 * @brief Function for returning the address of a specific EGU TRIGGER task register.
 *
 * @param NRF_EGUx EGU instance.
 * @param channel  Channel number.
 */
__STATIC_INLINE uint32_t * nrf_egu_task_trigger_addres_get(NRF_EGU_Type * NRF_EGUx,
                                                           uint8_t channel)
{
    ASSERT(channel < NRF_EGU_CHANNEL_COUNT);
    return (uint32_t*)&NRF_EGUx->TASKS_TRIGGER[channel];
}


/**
 * @brief Function for returning the specific EGU TRIGGER task.
 *
 * @param channel  Channel number.
 */
__STATIC_INLINE nrf_egu_task_t nrf_egu_task_trigger_get(uint8_t channel)
{
    ASSERT(channel <= NRF_EGU_CHANNEL_COUNT);
    return (nrf_egu_task_t)((uint32_t) NRF_EGU_TASK_TRIGGER0 + (channel * sizeof(uint32_t)));
}


/**
 * @brief Function for returning the state of a specific EGU event.
 *
 * @param NRF_EGUx  EGU instance.
 * @param egu_event EGU event to check.
 */
__STATIC_INLINE bool nrf_egu_event_check(NRF_EGU_Type * NRF_EGUx,
                                         nrf_egu_event_t egu_event)
{
    return (bool)*(volatile uint32_t *)((uint8_t *)NRF_EGUx + (uint32_t)egu_event);
}


/**
 * @brief Function for clearing a specific EGU event.
 *
 * @param NRF_EGUx  EGU instance.
 * @param egu_event EGU event to clear.
 */
__STATIC_INLINE void nrf_egu_event_clear(NRF_EGU_Type * NRF_EGUx,
                                         nrf_egu_event_t egu_event)
{
    *((volatile uint32_t *)((uint8_t *)NRF_EGUx + (uint32_t)egu_event)) = 0x0UL;
}


/**
 * @brief Function for returning the address of a specific EGU event register.
 *
 * @param NRF_EGUx  EGU instance.
 * @param egu_event EGU event.
 */
__STATIC_INLINE uint32_t * nrf_egu_event_address_get(NRF_EGU_Type * NRF_EGUx,
                                                     nrf_egu_event_t egu_event)
{
    return (uint32_t *)((uint8_t *)NRF_EGUx + (uint32_t)egu_event);
}


/**
 * @brief Function for returning the address of a specific EGU TRIGGERED event register.
 *
 * @param NRF_EGUx EGU instance.
 * @param channel  Channel number.
 */
__STATIC_INLINE uint32_t * nrf_egu_event_triggered_addres_get(NRF_EGU_Type * NRF_EGUx,
                                                              uint8_t channel)
{
    ASSERT(channel < NRF_EGU_CHANNEL_COUNT);
    return (uint32_t*)&NRF_EGUx->EVENTS_TRIGGERED[channel];
}


/**
 * @brief Function for returning the specific EGU TRIGGERED event.
 *
 * @param channel  Channel number.
 */
__STATIC_INLINE nrf_egu_event_t nrf_egu_event_triggered_get(uint8_t channel)
{
    ASSERT(channel < NRF_EGU_CHANNEL_COUNT);
    return (nrf_egu_event_t)((uint32_t) NRF_EGU_EVENT_TRIGGERED0 + (channel * sizeof(uint32_t)));
}


/**
 * @brief Function for enabling one or more specific EGU interrupts.
 *
 * @param NRF_EGUx     EGU instance.
 * @param egu_int_mask Interrupts to enable.
 */
__STATIC_INLINE void nrf_egu_int_enable(NRF_EGU_Type * NRF_EGUx, uint32_t egu_int_mask)
{
    NRF_EGUx->INTENSET = egu_int_mask;
}


/**
 * @brief Function for retrieving the state of one or more EGU interrupts.
 *
 * @param NRF_EGUx EGU instance.
 * @param egu_int_mask Interrupts to check.
 *
 * @retval true  If all of the specified interrupts are enabled.
 * @retval false If at least one of the specified interrupts is disabled.
 */
__STATIC_INLINE bool nrf_egu_int_enable_check(NRF_EGU_Type * NRF_EGUx, uint32_t egu_int_mask)
{
    return (bool)(NRF_EGUx->INTENSET & egu_int_mask);
}


/**
 * @brief Function for disabling one or more specific EGU interrupts.
 *
 * @param NRF_EGUx     EGU instance.
 * @param egu_int_mask Interrupts to disable.
 */
__STATIC_INLINE void nrf_egu_int_disable(NRF_EGU_Type * NRF_EGUx, uint32_t egu_int_mask)
{
    NRF_EGUx->INTENCLR = egu_int_mask;
}

/**
 * @brief Function for retrieving one or more specific EGU interrupts.
 *
 * @param channel Channel number.
 *
 * @returns EGU interrupt mask.
 */
__STATIC_INLINE nrf_egu_int_mask_t nrf_egu_int_get(uint8_t channel)
{
    ASSERT(channel < NRF_EGU_CHANNEL_COUNT);
    return (nrf_egu_int_mask_t)((uint32_t) (EGU_INTENSET_TRIGGERED0_Msk << channel));
}

/** @} */

#endif
