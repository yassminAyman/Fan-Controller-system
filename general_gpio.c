/*
 ============================================================================
 Name        : general_gpio.c
 Author      : Yassmin
 Version     :
 Copyright   : Your copyright notice
 Description : GPIO
 ============================================================================
 */

#include "avr/io.h"
#include "general_gpio.h"
#include "common_macros.h"

/*
 * DDRA|=1<<PC2;
 * */
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_Pin_Direction direction){
	if((port_num >= NUM_OF_PORTS) || (pin_num >=NUM_OF_PINS))
	{

	}
	else
	{
		switch(port_num){
		case PORTA_ID:
			if(direction==Pin_OUTPUT){
				SET_BIT(DDRA,pin_num);
			}
			else{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction==Pin_OUTPUT){
				SET_BIT(DDRB,pin_num);
			}
			else{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction==Pin_OUTPUT){
				SET_BIT(DDRC,pin_num);
			}
			else{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction==Pin_OUTPUT){
				SET_BIT(DDRD,pin_num);
			}
			else{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value)
{
	/*
	 * PORTA|=1<<PC3
	 * */
	if((port_num >= NUM_OF_PORTS) || (pin_num >=NUM_OF_PINS))
	{

	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH){
				SET_BIT(PORTA,pin_num);
			}
			else{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value== LOGIC_HIGH){
				SET_BIT(PORTB,pin_num);
			}
			else{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value== LOGIC_HIGH){
				SET_BIT(PORTD,pin_num);
			}
			else{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;

		}
	}
}

uint8 GPIO_readPin(uint8 port_num,uint8 pin_num)
{
	uint8 pin_value= LOGIC_LOW;
	if((port_num >= NUM_OF_PORTS) || (pin_num >=NUM_OF_PINS))
	{

	}
	else
	{
		switch(port_num){
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value= LOGIC_HIGH;
			}
			else
			{
				pin_value=  LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value= LOGIC_HIGH;
			}
			else
			{
				pin_value=  LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value= LOGIC_HIGH;
			}
			else
			{
				pin_value=  LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value= LOGIC_HIGH;
			}
			else
			{
				pin_value=  LOGIC_LOW;
			}
			break;
		}

	}
	return pin_value;
}

void GPIO_setupPortDirection(uint8 port_num, GPIO_PORT_Direction direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}

void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{

	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		}
	}

	return value;
}