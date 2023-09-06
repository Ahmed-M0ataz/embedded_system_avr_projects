/*
 * main.c
 *
 *  Created on: Nov 5, 2021
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
#include"spi_Interface.h"




void main(void)
{

DIO_set_pin_direction(Group_B,DIO_Pin_7,DIO_Input);//clk
DIO_set_pin_direction(Group_B,DIO_Pin_6,DIO_Output);//miso
DIO_set_pin_direction(Group_B,DIO_Pin_5,DIO_Input);//mosi
DIO_set_pin_direction(Group_B,DIO_Pin_4,DIO_Input);//ss- البتايه الي بتشغل ان الاسليف دا الي هيشتغل البرتوكول
LCD_Intialization();

spi_init_slave();
u8 reseve;
while(1){
reseve=spi_transfer('S');
LCD_write_data(reseve);
}



}
