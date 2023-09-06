/*
 * main.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Ahmed Moataz
 */


#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"



#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)//TIMER COUNT
#define ICR1L *((volatile u16*)0x46)//بصيت عليه كأنه 16 بت عشان كده كده الرجستر التاني الي بسيف فيه بقيت الداتا وراه علطول في الميموري ف مش لازم اعرف الرجستر الي بعد كده و كده كده اول م التاني يتملي هيسيف في التاني علطول
#define OCR1AL *((volatile u16*)0x4A)//compare match value IN pin ocr1a برده 2 رجستر زي الي فوق الخاصين بالبنايه  الي فيه القيمه الي بقارنها مع تاني رجستر
#define OCR1BL *((volatile u16*)0x48)//compare match value IN pin ocr1b  برده 2 رجستر زي الي فوق الخاصين بالبنايه  الي فيه القيمه الي بقارنها مع تاني رجستر




void __vector_10(void)  __attribute__((signal));


void __vector_10(void)
{}


void main(void)
{
	DIO_set_pin_direction(Group_D,DIO_Pin_5,DIO_Output);


//ADC_INT();

//REGISTER TCCR1 bits (7 and 6 make pin oc1A  5 and 4  pin oc1B) put 1 and 1 to make pin oc1A and oc1B set oc1A and ocr1B on compare match , clear OC1A AND OCR1B at TOP value (255) (mode inverted ) data sheet page 105
	TCCR1A=0b10100010;//(bit 0 and bit 1 with 2 bits from rigester tccr1b bit 3 and 4 : configer timer 1 in pwm or ctc or...) prescaler 8 mhz (divid 8000000/8 to get 1000000 mhz (prescaler bits 0,1,2)
	TCCR1B=0b00011011;//bit 0 and 1 and 2  prescaler 8 mhz (divid 8000000/8 to get 1000000 mhz (prescaler bits 0,1,2)
	ICR1L=2499;//put top value  and minase 1 (2500 - 1 = 2499)
	OCR1AL= 360;//188 FOR 1.5 MSEC ( ANGLE 90 ) (1.5*(65536(2^16 reselution))/524.288(time of over flow for 16 bit resilution))
	//85 for 0 angle
	//set_bit(TIMSK,1);

	while(1)
	{

		for (u16 i=85;i<390;i++)
		{
			OCR1AL= i;
			_delay_ms(20);

		}

	}




}
