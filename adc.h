/*
 * adc.h
 *
 *  Created on: Jun 17, 2023
 *      Author: yassmin
 */
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/****************************DEFINATIONS****************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*To determine the required voltage*/
typedef enum
{
	AREF,AVCC,INTERNAL_VOLT_2_56=3
}ADC_ReferenceVolatge;

/*To determine the required Prescaler*/
typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/***********************FUNCTIONS PROTOTYPES***********************/
void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 ch_num);

#endif
