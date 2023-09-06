/*
 * main.c
 *
 *  Created on: Nov 12, 2021
 *      Author: Ahmed Moataz
 */


#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"

#include"LCD_Interface.h"
#include"RTOS_interface.h"





#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)//TIMER COUNT
#define TIMSK *((volatile u8*)0x59)//over flow intrupt
#define SREG *((volatile u8*)0x5F)

u8 flag=0;
void __vector_11(void)  __attribute__((signal));


void __vector_11(void)
{
static u16 count=0;
count++;
if(count==3907)
{
count=0;
TCNT0=192;//ارجعه تاني للربع الي عاوز اعده
//DIO_set_pin_value(Group_D,DIO_Pin_0,toggle_bit(state,0));
tick_count++;
scheduler();
//led_counter++;//دا كده بيزيد لما يعدي ثانيه
flag=1;
}}
void led_1(void)
{
	static u8 state_1=0;
DIO_set_pin_value(Group_C,DIO_Pin_0,toggle_bit(state_1,0));

}

void led_2(void)
{
	static u8 state_2=0;
DIO_set_pin_value(Group_C,DIO_Pin_1,toggle_bit(state_2,0));

}

void led_3(void)
{
	static u8 state_3=0;
DIO_set_pin_value(Group_C,DIO_Pin_2,toggle_bit(state_3,0));

}
void main(void)
{//static u8 state_1=0,state_2=0,state_3=0;
	DIO_set_pin_direction(Group_C,DIO_Pin_0,DIO_Output);
	DIO_set_pin_direction(Group_C,DIO_Pin_1,DIO_Output);
	DIO_set_pin_direction(Group_C,DIO_Pin_2,DIO_Output);

	TCCR0=0b00000010;//bit 3 and bit 6 for modes 0 and 0 normal mode and prescaler 8 mhz (divid 8000000/8 to get 1000000 mhz (prescaler bits 0,1,2)
	TCNT0=192;//192 preload
	set_bit(TIMSK,0);//enable over flow interupt like  sie (spisific intrupt enable)
	set_bit(SREG,7);//enable over flow interupt like  gie (global intrupt enable)
task_creation(0,1,led_1);
task_creation(1,2,led_2);
task_creation(2,3,led_3);

	while(1){


	}

}
