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
{u8 local_key;
	kpd_set_init();


	DIO_set_pin_direction(Group_B,DIO_Pin_0,DIO_Output);
	DIO_set_pin_direction(Group_B,DIO_Pin_1,DIO_Output);

	while(1)
	{

	DIO_set_pin_value(Group_A,DIO_Pin_0,DIO_Low);
	//_delay_ms(3000);

	DIO_set_pin_value(Group_A,DIO_Pin_1,DIO_High);
	_delay_ms(1000);

	DIO_set_pin_value(Group_A,DIO_Pin_1,DIO_Low);

	DIO_set_pin_value(Group_A,DIO_Pin_0,DIO_High);
//		//_delay_ms(3000);

	}

	// relay ********************
	//transestor ************
	//optocapler***************

}
