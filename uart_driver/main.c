/*
 * main.c
 *
 *  Created on: Oct 30, 2021
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
#include"uart_interface.h"








void main (void)
{

	DIO_set_pin_direction(Group_D,DIO_Pin_0,DIO_Input);
	DIO_set_pin_direction(Group_D,DIO_Pin_0,DIO_Output);
LCD_Intialization();
	UART_init();
	u8 ch;//u8 arr[6]="ahmed";

	while(1)
	{
		ch = UART_RECEIVE_CHAR();
		LCD_write_data(ch);
	//	UART_SEND_STRING(arr);
	}





}
