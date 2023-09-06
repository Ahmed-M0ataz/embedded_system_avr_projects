/*
 * LCD_PROGRAM.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Ahmed Moataz
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#define F_CPU 800000000
#include "avr/delay.h"
#include "DIO_interface.h"
#include"LCD_CONFIG.h"
#include"LCD_PRIVATE.h"
#include"LCD_INTERFACE.h"

//write command in lcd rs put low (rs: register select)
//******************************************study***********************
void send_command(u8 command)
{//rs low to write command
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	//rw low to write not read
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	//set command in pins
	DIO_SET_PORT_VALUE(LCD_DATA_PORT,command);
//final eneble the lcd to lcd know the data or command sent (pulse)
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

}
void send_data(u8 data)
{//rs low to write command
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	//rw low to write not read
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	//set command in pins
	DIO_SET_PORT_VALUE(LCD_DATA_PORT,data);
//final eneble the lcd to lcd know the data or command sent (pulse)
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

}
//*****************************************************************
void LCD_WRITE_CMD(u8 CMD)
{
	 DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

	 LCD_WRITE(CMD);

}
//write DATA in lcd rs put high

void LCD_WRITE_DATE(u8 DATA)
{

	 DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	 LCD_WRITE(DATA);
}
//TO write data and enable lcd to write data
void LCD_WRITE(u8 VALUE)
{

	 DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
for(u8 i=0;i<8;i++)
{
	 DIO_SET_PIN_VALUE(LCD_DATA_PORT,i,get_bit(VALUE,i));

}
DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);//TO enable LCD TO OPEN DOOR
_delay_ms(1); //pulse to enable
DIO_SET_PIN_VALUE(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);//TO enable LCD TO OPEN DOOR


}
//to initiolazation lcd page 13 data sheet lcd
void LCD_INIT(void)
{

	 DIO_SET_PORT_DIRECTION(LCD_DATA_PORT,DIO_MAX_PORT_VALUE);

	 DIO_SET_PIN_DIRECTION(LCD_DATA_PORT,LCD_RS_PIN,DIO_OUTPUT);
	 DIO_SET_PIN_DIRECTION(LCD_DATA_PORT,LCD_RW_PIN,DIO_OUTPUT);
	 DIO_SET_PIN_DIRECTION(LCD_DATA_PORT,LCD_E_PIN,DIO_OUTPUT);


	 _delay_ms(40);

	 LCD_WRITE_CMD(0b00111000);

	 _delay_us(50);

	 LCD_WRITE_CMD(0b00001100);
	 _delay_us(50);

	 LCD_WRITE_CMD(0b00000001);
	 _delay_ms(2);


}

