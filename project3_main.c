/*
 * project3_main.c
 *
 *  Created on: Jun 22, 2023
 *      Author: yassmin
 */

#include "adc.h"
#include "dc_motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "pwm.h"

int main(void)
{
	/*****************************variables:*****************************/
	ADC_ConfigType ADC_CONFIGRATION={INTERNAL_VOLT_2_56,F_CPU_8};	/*ADC config. 2.56v and F_CPU/8*/

	uint8 temp_value=0;		/*To store temp value which processed by the temp sensor*/

	uint8 fan_state=OFF;		/*To determine the FAN status*/

	/*********************initialization functions:*********************/
	LCD_init();
	ADC_init(&ADC_CONFIGRATION);
	DcMotor_Init();

	while(1)
	{
		/*determine which case we are facing and control the fan*/
		temp_value= LM35_getTemperature();
		if(temp_value>0 && temp_value<30)
		{
			DcMotor_Rotate(stop, 0);
			fan_state=OFF;
		}
		else if(temp_value>=30 && temp_value<60)
		{
			DcMotor_Rotate(CW, 25);
			fan_state=ON;
		}
		else if(temp_value>=60 && temp_value<90)
		{
			DcMotor_Rotate(CW, 50);
			fan_state=ON;
		}
		else if(temp_value>=90 &&temp_value<120)
		{
			DcMotor_Rotate(CW,75);
			fan_state=ON;
		}
		else if(temp_value>=120)
		{
			DcMotor_Rotate(CW,100);
			fan_state=ON;
		}

		/*control the display of the LCD*/

		/*display FAN status:*/
		moveCursor(0,3);
		LCD_displayString("FAN IS ");
		if(fan_state==OFF)
		{
			LCD_displayString("OFF");
		}
		else
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}

		/*display Temp value:*/
		moveCursor(1,3);
		LCD_displayString("TEMP = ");

		moveCursor(1,10);
		LCD_intgerToString(temp_value);


		if(temp_value<100)
		{
			LCD_displayCharacter(' ');
			if(temp_value<10)
			{
				LCD_displayCharacter(' ');
			}
		}

		moveCursor(1,13);
		LCD_displayCharacter('C');
	}

}
