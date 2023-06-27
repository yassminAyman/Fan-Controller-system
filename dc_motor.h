/*
 * dc_motor.h
 *
 *  Created on: Jun 22, 2023
 *      Author: yassmin
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "general_gpio.h"
#include "std_types.h"

/***************************************DEFINATIONS***************************************/
#define MOTOR_PORT_ID					PORTB_ID
#define MOTOR_FIRST_INPUT_PIN_ID		PIN0_ID
#define MOTOR_SECOND_INPUT_PIN_ID		PIN1_ID

/***************************************DATA TYPES***************************************/
typedef enum {
	CW,A_CW,stop
}DcMotor_State ;

/**********************************FUNCTIONS PROTOTYPES**********************************/
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
