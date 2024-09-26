/* 
 * File:   hal_timer1.h
 * Author: omar fathy
 *
 * Created on 14 July 2024, 12:59
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/* INCLUDES */
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/* MACRO DECLARATIONS */
#define TIMER1_TIMER_MODE            0
#define TIMER1_COUNTER_MODE          1

#define TIMER1_ASYNC_COUNTER_MODE    1
#define TIMER1_SYNC_COUNTER_MODE     0

#define TIMER1_OSCILLATOR_ENABLE     1
#define TIMER1_OSCILLATOR_DISABLE    0

#define TIMER1_PRESCALER_ENABLE_CFG  1
#define TIMER1_PRESCALER_DISABLE_CFG 0

#define TIMER1_8BIT_REGISTER_MODE    0
#define TIMER1_16BIT_REGISTER_MODE   1

/* MACRO FUNCTIONS DECLARATIONS */
#define TIMER1_PRESCALER_SELECT(_PRESCALER) (T1CONbits.T1CKPS = _PRESCALER)

#define TIMER1_TIMER_MODE_ENABLE()          (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_MODE_ENABLE()        (T1CONbits.TMR1CS = 1)

#define TIMER1_ASYNC_COUNTER_MODE_ENABLE()  (T1CONbits.T1SYNC = 1)
#define TIMER1_SYNC_COUNTER_MODE_ENABLE()   (T1CONbits.T1SYNC = 0)

#define TIMER1_8BIT_REGISTER_MODE_ENABLE()  (T1CONbits.RD16 = 0)
#define TIMER1_16BIT_REGISTER_MODE_ENABLE() (T1CONbits.RD16 = 1)

#define TIMER1_MODULE_ENABLE()              (T1CONbits.TMR1ON = 1)
#define TIMER1_MODULE_DISABLE()             (T1CONbits.TMR1ON = 0)

#define TIMER1_OSCILLATOR_HW_ENABLE()       (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSCILLATOR_HW_DISABLE()      (T1CONbits.T1OSCEN = 0)

#define TIMER1_SYSTEM_CLK_STATUS()          (T1CONbits.T1RUN)

/* DATA TYPES DECLARATIONS */
typedef enum{
    TIMER1_PRESCALER_DIV_BY_1 = 0,
    TIMER1_PRESCALER_DIV_BY_2,
    TIMER1_PRESCALER_DIV_BY_4,
    TIMER1_PRESCALER_DIV_BY_8,
}timer1_prescaler_select_t;

typedef struct{
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TMR1_InterruptHandler)(void);
    interrupt_priority_t priority;
#endif
    timer1_prescaler_select_t prescaler_value;
    uint8 operation_mode : 1;
    uint8 counter_mode : 1;
    uint8 oscillator_cfg : 1;
    uint16 preload_value;
    uint8 register_size : 1;
    uint8 timer1_reserved : 2;
}timer1_t;

/* FUNCTIONS DECLARATIONS */
Std_ReturnType timer1_initialize(const timer1_t *timer);
Std_ReturnType timer1_deinitialize(const timer1_t *timer);
Std_ReturnType timer1_write_value(const timer1_t *timer, uint16 value);
Std_ReturnType timer1_read_value(const timer1_t *timer, uint16 *value);

#endif	/* HAL_TIMER1_H */

