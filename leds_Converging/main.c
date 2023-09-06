/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Ahmed Moataz
 */
#include"avr/io.h"
#include"avr/delay.h"

void main (void)
{

	DDRA =255;
	while(1)
	{char conv=7;
		for(int i=0;i<4;i++)
		{
		PORTA =1<<i | 1<<conv;
		//_delay_ms(1)
		//PORTA=256>>i;
		_delay_ms(500);
		conv--;



		}
	}
}

