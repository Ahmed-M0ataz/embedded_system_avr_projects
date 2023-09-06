/*
 * main.c
 *
 *  Created on: Nov 6, 2021
 *      Author: Ahmed Moataz
 */

#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"

#include"LCD_Interface.h"
#include"i2c_interface.h"




void main (void)
{
	u8 arr[]="moataz", lcd[7];u8 i=0;
	LCD_Intialization();
	i2c_init_master();
	i2c_start();
	i2c_master_transmit_address(0b10100000);//بعت العنوان وقولتلو بلوك 0 وقولتله هكتب
	i2c_master_transmit_address(0b00000000);//هبدا كتابه من لوكيشن زيرو
	for(i=0;i<6;i++)
	{
	i2c_master_transmit_data(arr[i]);
	}
	i2c_stop();

_delay_ms(10);
//عشان اعمل رييد
//
i2c_start();
	i2c_master_transmit_address(0b10100000);//بعت العنوان وقولتلو بلوك 0 وقولتله هكتب
	i2c_master_transmit_address(0b00000000);
	i2c_start();
	i2c_master_transmit_address(0b10100001);//بعت العنوان وقولتلو بلوك 0 وقولتله 1 هقرا
	for(i=0;i<6;i++)
	{
	lcd[i]=i2c_master_receive_ack();
	}
	lcd[i]='\0';

	i2c_master_receive_not_ack();
	i2c_stop();
	LCD_WRITE_POS(lcd,0,0);

while(1)
{}
}
