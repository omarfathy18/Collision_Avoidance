/* 
 * File:   application.h
 * Author: Omar Mohamed Fathy
 * Submitted to : ASU Racing Team
 * Created on September 26, 2024, 7:16 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/***************************************Includes***************************************/

#include "ECU_Layer/ecu_layer_initialize.h"
#include "MCAL_Layer/mcal_layer_initialize.h"
#include <builtins.h> 

/***********************************Macro Declarations**********************************/

/******************************Macro Function Declarations******************************/

/***********************************Datatype Declarations*******************************/

/*********************************** ECU Externs *******************************/

extern led_t led_1;
extern led_t buzzer;

/*********************************** MCAL Externs *******************************/

extern eusart_t eusart_1;
extern adc_config_t adc_1;
extern ccp_t ccp1_pwm;
extern ccp_t ccp2_pwm;
extern timer0_t timer0_obj;
extern timer2_t timer;

/***********************************Function Declarations*******************************/

void application_initialize(void);

#endif	/* APPLICATION_H */

