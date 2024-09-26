/* 
 * File:   hal_ccp_cfg.h
 * Author: Omar Mohamed Fathy
 * Submitted to : ASU Racing Team
 * Created on September 26, 2024, 7:16 PM
 */

#ifndef HAL_CCP_CFG_H
#define	HAL_CCP_CFG_H

/***************************************Includes***************************************/

/***********************************Macro Declarations**********************************/

#define CCP_CFG_CAPTURE_MODE_SELECTED  0x00
#define CCP_CFG_COMPARE_MODE_SELECTED  0x01
#define CCP_CFG_PWM_MODE_SELECTED      0x02

#define CCP1_CFG_SELECTED_MODE (CCP_CFG_COMPARE_MODE_SELECTED)
#define CCP2_CFG_SELECTED_MODE (CCP_CFG_PWM_MODE_SELECTED)

/******************************Macro Function Declarations******************************/

/***********************************Datatype Declarations*******************************/

/***********************************Function Declarations*******************************/

#endif	/* HAL_CCP_CFG_H */

