/* 
 * File:   mcal_layer_initialize.c
 * Author: Omar Mohamed Fathy
 * Submitted to : ASU Racing Team
 * Created on September 26, 2024, 7:16 PM
 */
#include "mcal_layer_initialize.h"

extern void ADC_DefaultInterruptHandler(void);
extern void Timer0_DefaultInterruptHandler(void);

eusart_t eusart_1 = {
    .EUSART_TxInterruptHandler = NULL,
    .EUSART_RxInterruptHandler = NULL,
    .EUSART_FramingErrorHandler = NULL,
    .EUSART_OverrunErrorHandler = NULL,
    .baudrate = 9600,
    .baudrate_config = BAUDRATE_ASYN_8BIT_lOW_SPEED,
    .eusart_tx_cfg.eusart_tx_enable = EUSART_ASYNCHRONOUS_TX_ENABLE,
    .eusart_tx_cfg.eusart_tx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE,
    .eusart_tx_cfg.eusart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE,
    .eusart_rx_cfg.eusart_rx_enable = EUSART_ASYNCHRONOUS_RX_ENABLE,
    .eusart_rx_cfg.eusart_rx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE,
    .eusart_rx_cfg.eusart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE,
};

ccp_t ccp1_pwm = {
    .ccp_inst = CCP1_INST,
    .CCP1_InterruptHandler = NULL,
    .CCP1_priority = INTERRUPT_LOW_PRIORITY,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 50000,
    .timer2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1,
    .timer2_postscaler_value = CCP_TIMER2_POSTSCALER_DIV_BY_1,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN2,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
};

timer2_t timer = {
  .TMR2_InterruptHandler = NULL,
  .timer2_prescaler = TIMER2_PRESCALER_DIV_BY_1,
  .timer2_postscaler = TIMER2_POSTSCALER_DIV_BY_1,
  .timer2_preload_value = 0,
};

timer0_t timer0_obj = {
    .TMR0_InterruptHandler = Timer0_DefaultInterruptHandler,
    .operation_mode = TIMER0_TIMER_MODE,
    .register_size = TIMER0_16BIT_REGISTER_MODE,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_16,
    .preload_value = 3036
};

//adc_config_t adc_1 = {
//    .ADC_InterruptHandler = ADC_DefaultInterruptHandler,
//    .acquisition_time = ADC_12_TAD,
//    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
//    .adc_channel = ADC_CHANNEL_AN0,
//    .result_format = ADC_RIGHT_FORMAT,
//    .voltage_reference = ADC_VOLTAGE_REF_DISABLE
//};

void mcal_layer_initialize(void){
    Std_ReturnType retVal = E_NOT_OK; //fixed
    
    retVal = EUSART_ASYNC_Init(&eusart_1);
    
    retVal = CCP_Init(&ccp1_pwm);
    retVal = timer0_initialize(&timer0_obj);
    retVal = Timer2_Init(&timer);
    
//    retVal = ADC_Init(&adc_1);
}