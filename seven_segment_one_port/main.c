/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Ahmed Moataz
 */
#include"avr/io.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include"BIT_CALC.h"
void main (void)
{DDRA=255;
DDRD=255;
char i;
	char arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	while(1)
	{
		for(i=0;i<10;i++)
		{
		PORTD=0b00000011;
		PORTA=arr[i];
		PORTD=0b01000010;
		_delay_ms(10);
		PORTD=0b00000011;
		PORTA=arr[i+1];
		PORTD=0b10000001;
		_delay_ms(10);





		}

//_delay_ms(500);

	}








}

