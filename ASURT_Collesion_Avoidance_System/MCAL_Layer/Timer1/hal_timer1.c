/* 
 * File:   hal_timer1.h
 * Author: omar fathy
 *
 * Created on 14 July 2024, 12:59
 */

#include "hal_timer1.h"

#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static void (* TMR1_InterruptHandler)(void) = NULL;
#endif

static uint16 Timer1_preload = ZERO_INIT;

static inline void timer1_mode_select(const timer1_t *timer);

/**
 * @brief Initialize the Timer1 module
 * @param timer (Pointer to the timer configuration)
 * @return State of the function
 */
Std_ReturnType timer1_initialize(const timer1_t *timer){
    Std_ReturnType ret = E_NOT_OK;
    
    if(timer == NULL){
        ret = E_NOT_OK;
    }
    else{
        TIMER1_MODULE_DISABLE();
        TIMER1_PRESCALER_SELECT(timer->prescaler_value);
        timer1_mode_select(timer);
        TMR1H = (uint8)((timer->preload_value) >> 8);
        TMR1L = (uint8)(timer->preload_value);
        Timer1_preload = timer->preload_value;
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        Timer1_Interrupt_Enable();
        Timer1_Interrupt_FlagClear();
        TMR1_InterruptHandler = timer->TMR1_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        if(timer->priority == INTERRUPT_PRIORITY_HIGH){
            INTERRUPT_GlobalInterruptEnableHigh();
            Timer1_SetHighPriority();
        }
        else if(timer->priority == INTERRUPT_PRIORITY_LOW){
            INTERRUPT_GlobalInterruptEnableLow();
            Timer1_SetlowPriority();
        }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        TIMER1_MODULE_ENABLE();
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief Deinitialize the Timer1 module
 * @param timer (Pointer to the timer configuration)
 * @return State of the function
 */
Std_ReturnType timer1_deinitialize(const timer1_t *timer){
    Std_ReturnType ret = E_NOT_OK;
    
    if(timer == NULL){
        ret = E_NOT_OK;
    }
    else{
        TIMER1_MODULE_DISABLE();
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        Timer1_Interrupt_Disable();
#endif
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief Write value in the timer1 register
 * @param timer (Pointer to the timer configuration)
 * @param value (The value to write in the timer register)
 * @return State of the function
 */
Std_ReturnType timer1_write_value(const timer1_t *timer, uint16 value){
    Std_ReturnType ret = E_NOT_OK;
    
    if(timer == NULL){
        ret = E_NOT_OK;
    }
    else{
        TMR1H = (uint8)(value >> 8);
        TMR1L = (uint8)(value);
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief Write value in the timer1 register
 * @param timer (Pointer to the timer configuration)
 * @param value (Pointer to the value read from the timer register)
 * @return State of the function
 */
Std_ReturnType timer1_read_value(const timer1_t *timer, uint16 *value){
    Std_ReturnType ret = E_NOT_OK;
    
    if((timer == NULL) || (value == NULL)){
        ret = E_NOT_OK;
    }
    else{
        uint8 l_tmr1h = ZERO_INIT, l_tmr1l = ZERO_INIT;
        l_tmr1h = TMR1H;
        l_tmr1l = TMR1L;
        *value = (uint16)((l_tmr1h << 8) + l_tmr1l);
        ret = E_OK;
    }
    return ret;
}

void TMR1_ISR(void){
    Timer1_Interrupt_FlagClear();
    TMR1H = (uint8)(Timer1_preload >> 8);
    TMR1L = (uint8)Timer1_preload;
    if(TMR1_InterruptHandler){
        TMR1_InterruptHandler();
    }
}

static inline void timer1_mode_select(const timer1_t *timer){
    if(timer->operation_mode == TIMER1_TIMER_MODE){
        TIMER1_TIMER_MODE_ENABLE();
    }
    else if(timer->operation_mode == TIMER1_COUNTER_MODE){
        TIMER1_COUNTER_MODE_ENABLE();
        if(timer->counter_mode == TIMER1_ASYNC_COUNTER_MODE){
            TIMER1_ASYNC_COUNTER_MODE_ENABLE();
        }
        else if(timer->counter_mode == TIMER1_SYNC_COUNTER_MODE){
            TIMER1_SYNC_COUNTER_MODE_ENABLE();
        }
    }
}