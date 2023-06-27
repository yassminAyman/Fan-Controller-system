/*
 * acd.c
 *
 *  Created on: Jun 27, 2023
 *      Author: yassmin
 */
#include <avr/io.h>
#include "common_macros.h"
#include "adc.h"

/*void ADC_init(const ADC_ConfigType * Config_Ptr):
 * Description:
 * The Function responsible for initialize the ADC with the polling technique
 * Inputs: constant pointer to struct for dynamic config
 * Return: None
 * */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*ADMUX:
	 *bits 7,6:		reference voltage
	 *bit 5: 		clear for left adjust the presentation of the bits
	 *bit 0->4: 	set channel number at the read func
	 * */

	/*dynamic config for the reference voltage :*/
	ADMUX=(ADMUX&0x3F)|((Config_Ptr->ref_volt)<<7);

	/*ADCSRA:
	 * bit 7:		set ADEN to enable ADC
	 * bit 6:		we will set ADSC to start convertion at read func.
	 * bits 5,4:	clear
	 * bit 3:		clear ADIE to close intterupt
	 * bits 0->2:	Prescaler
	 * */
	ADCSRA= (1<<ADEN) ;

	/*dynamic config for the prescaler:*/
	ADCSRA=(ADCSRA&0xF8)|(Config_Ptr->prescaler);
}


/*uint16 ADC_readChannel(uint8 ch_num):
 * Description:
 * The Function responsible for reading the data from the sensor
 * and convert it to digital
 * Inputs: channel number(where the sensor is connected)
 * Return: the data that converted by the ADC
 * */
uint16 ADC_readChannel(uint8 ch_num)
{
	/*determine the channel*/
	ADMUX= (ADMUX &0xE0) | (ch_num);

	/*set ADSC to start convertion*/
	ADCSRA |= (1<<ADSC);

	/*wait for conversion to complete when ADIF becomes 1 */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/*clear ADIF by write 1 to it :) */
	SET_BIT(ADCSRA,ADIF);

	return ADC;
}
