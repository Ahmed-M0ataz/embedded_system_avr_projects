/*
 * uart_program.c
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
#include"uart_private.h"







void UART_init(void)
{
//bit 6 work asynclonas or sync (0 for async , 1 for sync )
//bit 5 and 4 config parity (00 disable .....date sheet page 161 )
//bit 3 config num of stop bit (0 for 1 stop bit or 1 for 2 stop bit )
//bit 2 and bit 1 in this register and bit 2 in register ucsrb (all this config size data from 5 to 9 )
// bit 0 clock polarity (in async not important )
	UCSRC = 0b10000110;//bit 7 if write 1 call and save date in ucsrc else if write 0  call and save date in ubrrh

//bit 7 disable rx complete int
	//bit 6 disable tx complete int
	//bit 5 disable tx data register empty
//bit 4 rx  receve data enable  power on
	//bit 3 tx enable trancmate data power on
//bit 2 from 3 bit (size data)
//bit 1 if size data 9 bit (the bit 9 save here )(receve data)
	//bit 0 if size data 9 bit (the bit 9 send data from here ) (transmation)

	UCSRB= 0b00011000;


//for boud rate 12 bit in register ubrrl and ubrrh save the 8 bit in ubrrl and 4 bit in ubrrh

	UBRRH=0;//هنا هحتاج بس البت ال9 بس كده كده ال51 تتسيف في الرجستر اللو بس مش محتاج الاربع بتات التانيين
	UBRRL=51;//boud rate (freq system / (16 * rate)) equation for boud rate
}

void UART_SEND_CHAR(u8 data)//char 1 byte عشان انا عملت كونفيج انها تبعت 8 بت
	{
while (get_bit(UCSRA,5)==0);

	UDR= data;


	}
u8 UART_RECEIVE_CHAR(void)//char 1 byte عشان انا عملت كونفيج انها تبعت 8 بت
	{
while (get_bit(UCSRA,7)==0);

	return UDR;


	}

void UART_SEND_STRING(u8 *str)
{
	while(*str != '\0')
	{
	UART_SEND_CHAR(*str);
	str++;
	}


}

void UART_RECEIVE_STRING(u8 *str)
{
	u8 i=0;
while(i<8)
{
str[i]=	UART_RECEIVE_CHAR();
i++;
}

str[i]='\0';




}




