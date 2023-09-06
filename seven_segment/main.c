/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Ahmed Moataz
 */

#include "avr/io.h"
#include"avr/delay.h"

void main (void)
{DDRA=255;
DDRD=255;
char i;
	char arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	while(1)
	{
	for(i=0;i<10;i++)
	{
		PORTA=arr[i];
		_delay_ms(50);
		for(int j=0;j<10;j++)
		{
			PORTD=arr[j];
			_delay_ms(100);

		}
		}

	}



}
