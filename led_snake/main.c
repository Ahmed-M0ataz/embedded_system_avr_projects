/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Ahmed Moataz
 */
#include"avr/io.h"
#include"avr/delay.h"
#include"BIT_CALC.h"
void main (void)
{char i,count=0;
	DDRA=255;
	while(1)
	{PORTA=0b00000000;
       for( i=0;i<8;i++)
       {
		PORTA|=(1<<i);
		_delay_ms(500);



       }
       for(char k=0;k<8;k++)
       {

    	   	   PORTA^=(1<<k);
    	   	   _delay_ms(500);

    	   if (k>1)		set_bit(PORTA,k);
    	   				_delay_ms(500);




    	   				count++;
       }
     //  PORTA|=(1<<0);_delay_ms(500);

	}






}

