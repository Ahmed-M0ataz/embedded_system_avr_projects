/*
 * main.c
 *
 *  Created on: Oct 9, 2021
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



void main (void)
{

	u16 digital;
f32 analog;
f32 temp;
	DIO_set_pin_direction(Group_A,DIO_Pin_0,DIO_Input);
//	DIO_set_pin_direction(Group_B,DIO_Pin_5,DIO_Output);
	//DIO_set_pin_direction(Group_B,DIO_Pin_6,DIO_Output);
//	DIO_set_pin_direction(Group_B,DIO_Pin_7,DIO_Output);
	LCD_Intialization();
ADC_INT();
while(1)
{
	digital=ADC_READ(ADC_CH_0);//عدد العدات digital is steps
analog=(digital*refrance_volt)/resolution;//عشان اعرف الفولت هستخدم المعادله بناعت الإستبس
temp=(analog*100.0);//الأنالوج مضروب في 1000 عشان احوله للملي وبعدين هقسمه علي 10ملي فولت

LCD_WRITE_num(analog);
_delay_ms(1000);
LCD_write_cmd(0b00000001);
/*
if (analog>=0&&analog<1.5)
{
	DIO_set_pin_value(Group_B,DIO_Pin_5,DIO_High);
	DIO_set_pin_value(Group_B,DIO_Pin_6,DIO_Low);
	DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_Low);
	//LCD_WRITE_num(digital);

}
else if (analog>=1.5&&analog<3)
{
	DIO_set_pin_value(Group_B,DIO_Pin_5,DIO_Low);
		DIO_set_pin_value(Group_B,DIO_Pin_6,DIO_High);
		DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_Low);
	//	LCD_WRITE_num(digital);

}
else
{
	DIO_set_pin_value(Group_B,DIO_Pin_5,DIO_Low);
			DIO_set_pin_value(Group_B,DIO_Pin_6,DIO_Low);
			DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_High);
		//	LCD_WRITE_num(digital);

}
//_delay_ms(3000);
}*/



}
}
