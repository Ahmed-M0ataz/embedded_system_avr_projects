/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Ahmed Moataz
 */
#include"avr/io.h"
#include"BIT_CALC.h"
#include"avr/delay.h"
void main (void)
{
	clear_bit(DDRC,0);
//DDRC=0b00000010;
//PORTC=0b00000001;

	set_bit(DDRC,1);
	set_bit(PORTC,0);//make resistace internal micro prosesor pull up
	while(1)
	{

		if(get_bit(PINC,0)==0)
		{

		set_bit(PORTC,1);}

		else
			clear_bit(PORTC,1);




	}



}
