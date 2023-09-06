/*
 * main.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Ahmed Moataz
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#define F_CPU 800000000
#include "avr/delay.h"
#include "DIO_interface.h"
#include"LCD_INTERFACE.h"

void main(void)
{

	void LCD_INIT();
	LCD_WRITE_DATE('A');
	LCD_WRITE_DATE('h');

	LCD_WRITE_DATE('m');
	LCD_WRITE_DATE('e');
	LCD_WRITE_DATE('d');
	while(1)
	{}





}
