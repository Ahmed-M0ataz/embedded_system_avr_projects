/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Ahmed Moataz
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#define F CPU 8000000
#include "avr/delay.h"

#include "DIO_interface.h"

void main(void)
{
	DIO_SET_PIN_DIRECTION(GROUP_D,DIO_PIN_0,DIO_INPUT);
	DIO_SET_PIN_VALUE(GROUP_D,DIO_PIN_0,DIO_HIGH);//TO PIN WORK PULL UP
	DIO_SET_PIN_DIRECTION(GROUP_D,DIO_PIN_1,DIO_OUTPUT);
	u8 result;
	while (1)
	{
		DIO_GET_PIN_VALUE(GROUP_D,DIO_PIN_0,&result);
				if (result==0)
					DIO_SET_PIN_VALUE(GROUP_D,DIO_PIN_1,DIO_HIGH);
				else
					DIO_SET_PIN_VALUE(GROUP_D,DIO_PIN_1,DIO_LOW);




	}

}
