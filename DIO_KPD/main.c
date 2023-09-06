/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Ahmed Moataz
 */

#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"

#include"LCD_Cofiguration.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"
#include "kpd_Interface.h"

void main(void)
{
	DIO_set_pin_direction(Group_B,DIO_Pin_0,DIO_Output);
	DIO_set_pin_direction(Group_B,DIO_Pin_1,DIO_Output);
	//LCD_Intialization;
	u8 arr[16];
	kpd_set_init();
	while(1)
	{
		kpd_get_state(arr);
		if(arr[0]==kpd_pressed)

		{
		DIO_set_pin_value(Group_B,DIO_Pin_0,DIO_High);
		DIO_set_pin_value(Group_B,DIO_Pin_1,DIO_Low);
		LCD_WRITE_POS("rotation clock wise",0,0);

		}

		else if (arr[1]==kpd_pressed)
		{
			DIO_set_pin_value(Group_B,DIO_Pin_1,DIO_High);
			DIO_set_pin_value(Group_B,DIO_Pin_0,DIO_Low);
			LCD_write_cmd(0b00000001);
			LCD_WRITE_POS("rotation anti clock wise",0,0);



		}

		else
			{
			DIO_set_pin_value(Group_B,DIO_Pin_0,DIO_Low);
			DIO_set_pin_value(Group_B,DIO_Pin_1,DIO_Low);
			}


	}

}

