/* 
 * File:   mcal_layer_initialize.h
 * Author: Omar Mohamed Fathy
 * Submitted to : ASU Racing Team
 * Created on September 26, 2024, 7:16 PM
 */
#ifndef MCAL_LAYER_INITIALIZE_H
#define	MCAL_LAYER_INITIALIZE_H

/***************************************Includes***************************************/

#include "Interrupt/mcal_external_interrupt.h"
#include "Interrupt/mcal_internal_interrupt.h"
#include "ADC/hal_adc.h"
#include "CCP/hal_ccp.h"
#include "EUSART/hal_eusart.h"
#include "Timer0/hal_timer0.h"
#include "Timer2/hal_timer2.h"

/***********************************Macro Declarations**********************************/

/******************************Macro Function Declarations******************************/

/***********************************Datatype Declarations*******************************/

/***********************************Function Declarations*******************************/

void mcal_layer_initialize(void);

#endif	/* MCAL_LAYER_INITIALIZE_H */

