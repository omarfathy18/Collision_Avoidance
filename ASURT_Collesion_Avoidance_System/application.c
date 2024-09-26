/* 
 * File:   application.c
 * Author: Omar Mohamed Fathy
 * Submitted to : ASU Racing Team
 * Created on September 26, 2024, 7:16 PM
 */

#include "application.h"

//uint16 lm35_res_1;
//uint16 lm35_res1_cel;
//volatile uint8 adc_req;
//uint8 uart_sent_data;

volatile uint8 uart_received_data;

int main() {
    Std_ReturnType retVal = E_NOT_OK; //fixed
    application_initialize(); //fixed

    while(1){

        retVal = EUSART_ASYNC_Read_Byte_Blocking(&eusart_1 , &uart_received_data);

//        if(0 == adc_req){
//            retVal = ADC_Start_Conversion_Interrupt(&adc_1 , ADC_CHANNEL_AN0);
//        }
//        
//        lm35_res1_cel = lm35_res_1 * 4.88f;
//        
//        lm35_res1_cel /= 10;
//        
//        uart_sent_data = (uint8)lm35_res1_cel;
//
//        retVal = EUSART_ASYNC_Write_Byte_Non_Blocking(&eusart_1 , uart_sent_data);
    }

    return (EXIT_SUCCESS);
}

//void ADC_DefaultInterruptHandler(void){
//    ADC_Get_Conversion_Result(&adc_1 , &lm35_res_1);
//}

void Timer0_DefaultInterruptHandler(void){
    if(50 >= uart_received_data){
        led_toggle(&led_1);
        led_toggle(&buzzer);
    }
    else{
        led_turn_off(&led_1);
        led_turn_off(&buzzer);
    }
}

void application_initialize(void){
    Std_ReturnType retVal = E_NOT_OK; //fixed
    ecu_layer_initialize(); //fixed 
    mcal_layer_initialize(); //fixed
}
