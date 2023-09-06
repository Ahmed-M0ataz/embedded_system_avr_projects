/*
 *        main.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Ahmed Moataz
 */
#include"avr/io.h"
#include"avr/delay.h"
#include"BIT_CALC.h"

void main(void)
{	DDRA=0b11111111;
PORTA=0b00000000;
	while(1)
{

		/*set_bit(PORTA,0);

_delay_ms(500);
clear_bit(PORTA,0);
set_bit(PORTA,1);
_delay_ms(500);
clear_bit(PORTA,1);*/
PORTA=0b00000001;
_delay_ms(500);
PORTA=0b00000010;
_delay_ms(500);





}

}
