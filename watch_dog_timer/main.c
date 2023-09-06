/*
 * main.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Ahmed Moataz
 */
#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"

#define WDTCR *((volatile u8*)0x41) //REGISTER WATCH DOG





void main (void)
{
	DIO_set_pin_direction(Group_B,DIO_Pin_7,DIO_High);
	DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_High);
	_delay_ms(1000);
	DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_Low);

	WDTCR = 0b0001111;//bit 0,1,2 count time config time that count, bit 3  write 1 make watch dog enable
// وعشان اعمل ديسيبل للواتش دوج لازم احط علي بت 3 وبت 4 ->1 في نفس السيكل يعني نفس الوقت ونفس السطر
//تاني حاجه معايا 4 كلوك في خلالهم لازم اخلي بت 3 ب 0
while(1)
{}
}
