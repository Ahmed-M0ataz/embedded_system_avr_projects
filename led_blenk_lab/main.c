/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Ahmed Moataz
 */

#include"avr/io.h"//الي بتعرف ddr and porta and portb....
#include"avr/delay.h"
#include"BIT_CALC.h"

void main (void)
{

	DDRA=255;
	while(1)//true كده الوايل شغاله علطول هيا بتشتغل غلطول بس الصفر بيخليها فولس واي حاجه تانيه
	{
		for(char i=0;i<8;i++)
		{

	PORTA=1<<i;
	_delay_ms(500);

		}
		for(char j=6;j>0;j--)
				{

			PORTA=1<<j;
			_delay_ms(500);

				}


	}



}
