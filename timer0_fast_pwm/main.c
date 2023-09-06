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



#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)//TIMER COUNT
#define TIMSK *((volatile u8*)0x59)
#define OCR0 *((volatile u8*)0x5C)//compare match value الي فيه القيمه الي بقارنها مع تاني رجستر

#define SREG *((volatile u8*)0x5F)
u8 led_counter=0;
u8 flag=0;
void __vector_10(void)  __attribute__((signal));


void __vector_10(void)
{
//static u8 state=0;
//count++;
//if(count==3907)
//{
//count=0;
//TCNT0=192;//ارجعه تاني للربع الي عاوز اعده
//DIO_set_pin_value(Group_D,DIO_Pin_0,toggle_bit(state,0));
//led_counter++;//دا كده بيزيد لما يعدي ثانيه
//flag=1;
}
void main(void)
{static u8 state_1=0,state_2=0,state_3=0;

	DIO_set_pin_direction(Group_A,DIO_Pin_0,DIO_Input);
	DIO_set_pin_direction(Group_B,DIO_Pin_3,DIO_Output);
	//DIO_set_pin_direction(Group_D,DIO_Pin_2,DIO_Output);
ADC_INT();

//REGISTER TCCR0 bit 5 and 4 put 1 and 1 to make pin oc0 (groub b bin 3 ) set oc0 on compare match , clear OC0 at TOP value (255) (mode inverted ) data sheet page 79
	TCCR0=0b01111010;//bit 3 and bit 6 for modes 1 and 1 fast pwm  mode and prescaler 8 mhz (divid 8000000/8 to get 1000000 mhz (prescaler bits 0,1,2)
	//set_bit(TIMSK,1);
	//TCNT0=192;//192 preload
	//set_bit(TIMSK,0);//enable over flow interupt like  sie (spisific intrupt enable)
	//set_bit(SREG,7);//enable over flow interupt like  gie (global intrupt enable)

	while(1){
	OCR0= ADC_READ(ADC_CH_0)/4;

		/*if(flag==1)
		{
		if (led_counter%1==0)//هتشتغل علطول
		{
			DIO_set_pin_value(Group_D,DIO_Pin_0,toggle_bit(state_1,0));
		}
		if (led_counter%2==0)//تشتغل مع مضاعفات الاتنين
				{
					DIO_set_pin_value(Group_D,DIO_Pin_1,toggle_bit(state_2,0));
				}
		if (led_counter%3==0)
				{
					DIO_set_pin_value(Group_D,DIO_Pin_2,toggle_bit(state_3,0));//تشتغل مع مضاعفات التلاته
				}
		flag=0;
		}*/

	}

}

