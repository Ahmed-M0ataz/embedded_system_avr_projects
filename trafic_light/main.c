/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Ahmed Moataz
 */
#include"avr/io.h"
#include"avr/delay.h"
void main (void)
{DDRA=0b11111111;
DDRD=255;
char i,j;
char arr[3]={0b00000110,0b01011011,0b01001111};
	while(1)
	{
		for(i=0;i<3;i++)
		{_delay_ms(30);
			PORTA=1<<i;
			for(j=0;j<3;j++)
			{
				PORTD =arr[j];
				_delay_ms(1000);


			}
			_delay_ms(30);


		}




	}
}




