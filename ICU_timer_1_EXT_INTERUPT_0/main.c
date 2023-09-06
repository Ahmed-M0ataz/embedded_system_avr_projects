/*
 * main.c
 *
 *  Created on: Oct 23, 2021
 *      Author: Ahmed Moataz
 */



#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include"LCD_Cofiguration.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"

//rigester timer0
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)//TIMER COUNT
#define TIMSK *((volatile u8*)0x59)//for timer 0 and 1 page 110
#define OCR0 *((volatile u8*)0x5C)//compare match value الي فيه القيمه الي بقارنها مع تاني رجستر
//rigester timer1
#define TCCR1A *((volatile u8*)0x4F)//config timer
#define TCCR1B *((volatile u8*)0x4E)//config timer
#define ICR1L *((volatile u16*)0x46)//top valueبصيت عليه كأنه 16 بت عشان كده كده الرجستر التاني الي بسيف فيه بقيت الداتا وراه علطول في الميموري ف مش لازم اعرف الرجستر الي بعد كده و كده كده اول م التاني يتملي هيسيف في التاني علطول
#define OCR1AL *((volatile u16*)0x4A)//compare match value IN pin ocr1a برده 2 رجستر زي الي فوق الخاصين بالبنايه  الي فيه القيمه الي بقارنها مع تاني رجستر
#define OCR1BL *((volatile u16*)0x48)//compare match value IN pin ocr1b  برده 2 رجستر زي الي فوق الخاصين بالبنايه  الي فيه القيمه الي بقارنها مع تاني رجستر

#define TCNT1L *((volatile u16*)0x4C)//الي بعد فيه وبرده فيه رجسترين بس هاخد اللووو بس

//external interupt

#define MCUCR *((volatile u8*)0x55)//Raising edge or failling or change or... interrupt 0 and 1
//#define MCUCSR *((volatile u8*)0x54)//Raising edge or failling or change or... interrupt 2
#define GICR *((volatile u8*)0x5B)//enable or disable for prepheral
//#define GIFR *((volatile u8*)0x5A)//hard ware making flag bit 7 for int 1 bit 6 for int 0  bit 5 for int 2 (to i can remove flag 1 set bin 1  )
#define SREG *((volatile u8*)0x5F)//enable or disable for every prepherals  pit 7

u16 t_off , t_on ;

void __vector_6(void)  __attribute__((signal));


void __vector_6(void)

{
	static u8 flag=0;

	if (flag==0)
	{

	//t_off=TCNT1L;
		t_off=ICR1L;

		TCNT1L=0;//التيمر دا الي هخليه يقرا السجنل والتيمر الزيرو الي هخليه يخرج السجنل
		//MCUCR=0b00000010;//config ext intrupt falling edge
	 	TCCR1B=0b00000010;//config timer 1 prescaler 8 and ICU MODE SINCE RISING EDGE AND FALLING

		flag=1;


	}
	else
	{
		//t_on=TCNT1L;//in mode icu copy from reg tcnt1l  عشان مثلا لو كان فيه انتربت شغال غير دا ف مش هعرف اخش في الانربت دا ف القرايه الي لما اجي اخش هتبقي غلط عشان اللحظه الي جيت اخش لاقيته مشغول
		t_on=ICR1L;

		TCNT1L=0;
		//MCUCR=0b00000011;//config ext intrupt rising edge
	 	TCCR1B=0b01000010;//config timer 1 prescaler 8 and ICU MODE SINCE RISING EDGE AND FALLING

				flag=0;

	}


}




void main (void)
{u8 duty_cycle; u16 freq;
	//u8 arr[kpd_no_keys];
	LCD_Intialization();
	//kpd_set_init();
	DIO_set_pin_direction(Group_D,DIO_Pin_6,DIO_Input);
	DIO_set_pin_direction(Group_B,DIO_Pin_3,DIO_Output);

	TCCR0=0b01101010;//fast pwm , prescaler=8 , when compare match clear pin oc0 and set pit when top value (over flow value)

	OCR0=128;//compare match value اعمل عند الفاليو دي

	//MCUCR=0b00000011;//EXTERNAL intrupt  SENCE RISING EDGE in pin d2
	// GICR=0b01000000;//enable EXTI0 مش محتاهم في مود ال اي سي يو عشان تايمر 1 بيعرف يسنس ويعد في نفس الوقت في المود دا 1

	 	TCCR1A=0b00000000;//config timer 1 prescaler 8 and normal mode OR ICU MODE
	 	//TCCR1B=0b00000010;//config timer 1 prescaler 8 and normal mode
	 	TCCR1B=0b01000010;//config timer 1 prescaler 8 and ICU MODE SINCE RISING EDGE AND FALLING
	   	SREG=0b10000000;//global interupt enable
	   	TIMSK=0b00100000;//4 bit for timer 1 (bit 5 enable intrupt for mode ICU)

	   	LCD_WRITE_POS("ON=",0,0);
	   	LCD_WRITE_POS("OFF=",7,0);
	   	LCD_WRITE_POS("D=",0,1);
	   	LCD_WRITE_POS("F=",6,1);

while(1)
{
	duty_cycle=(t_on*100)/(t_on+t_off);//100 to get persintedg number (%) كام في الميه
	freq= (1*1000000)/(t_on+t_off);//1000000 التحويل من مايكرو لثانيه
go_pos(3,0);
	LCD_WRITE_num(t_on);

	go_pos(12,0);
		LCD_WRITE_num(t_off);
		go_pos(2,1);
				LCD_WRITE_num(duty_cycle);
				go_pos(8,1);
						LCD_WRITE_num(freq);



}




}

