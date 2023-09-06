/*
 * main.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Ahmed Moataz
 */

#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"

#include "EXT_interrpt_interface.h"

void blink_led(void)//(_1)->دي معناها ان انا كده عاوز اروح لمكان 2هو كده في الداتا شيت عشان اروح لمكان 2 في الفيكتور تيبول انقص منها 1واكتب اندراسكور الرقم الجديد
{
//frist ex
	//DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_High);
//secound ex
static u8 var=0;//معاناها انها بتطول الليف تايم للفاريبول عشان الفاريابول اللوكل بيتمسح اول ما اخلص اسكوب الفانكشن ststic
			toggle_bit(var,0);
			DIO_set_pin_value(Group_B,DIO_Pin_7,var);
}

void main(void)
{
	DIO_set_pin_direction(Group_B,DIO_Pin_7,DIO_Output);
	DIO_set_pin_direction(Group_D,DIO_Pin_2,DIO_Input);
	DIO_set_pin_value(Group_D,DIO_Pin_2,DIO_High);

	INT_SET_LEVEL(INT_0,INT_falling_edge);//لازم اخلي دي الاول عشان هو قال حطني انا هسنس ايي الاول وبعد كظده اعملي اينيبل
	set_call_back(INT_0,blink_led);
	INT_ENABLE_SPECIFIC_SIE(INT_0);
	INT_GLOBAL(INT_global_ENABLE);


while(1)
{

	/*INT_SET_LEVEL(INT_0,INT_falling_edge);//لازم اخلي دي الاول عشان هو قال حطني انا هسنس ايي الاول وبعد كظده اعملي اينيبل
		INT_ENABLE(INT_0);
		INT_GLOBAL(INT_global_ENABLE);*/

}



}


