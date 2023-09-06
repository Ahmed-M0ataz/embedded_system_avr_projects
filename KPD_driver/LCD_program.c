/*
     * LCD_program.c
 *
 *  Created on: Sep 11, 2021
 *      Author: user
 */
#include "BIT_CALC.h"
#include "std_types.h"
#define F_CPU 8000000
#include "avr/delay.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"


void LCD_write_cmd(U8 cmd)
{
    DIO_set_pin_value(LCD_control_port, LCD_rs_pin, DIO_Low );
	LCD_write(cmd);
}

void LCD_write_data(U8 data)
{
    DIO_set_pin_value( LCD_control_port, LCD_rs_pin, DIO_High );
	LCD_write(data);
}


void LCD_write(U8 value)
{
	DIO_set_pin_value(LCD_control_port,LCD_rw_pin, DIO_Low );

	for(int i=0;i<8;i++)
	{
		DIO_set_pin_value(LCD_data_port, i , get_bit( value,i));

	}

	DIO_set_pin_value(LCD_control_port,LCD_E_pin, DIO_High);
	_delay_ms(1);
	DIO_set_pin_value(LCD_control_port,LCD_E_pin,  DIO_Low);
}

void LCD_initial(void)
{
	DIO_set_port_direction(LCD_data_port, DIO_Max_port_direction);

	DIO_set_pin_direction(LCD_control_port ,LCD_rs_pin ,DIO_Output);

    DIO_set_pin_direction(LCD_control_port,LCD_rw_pin,DIO_Output);

    DIO_set_pin_direction(LCD_control_port,LCD_E_pin,DIO_Output);

    _delay_ms(40);
    LCD_write_cmd(0b00111000);
    _delay_us(50);
    LCD_write_cmd(0b00001100);
    _delay_us(50);
    LCD_write_cmd(0b00000001);
    _delay_ms(2);
}

// write string
void LCD_write_string(const char * string)
{
	U8 counter=0;
	while(string[counter] != '\0')
	{
		LCD_write_data(string[counter]);
		counter++;
	}
}

//shifting string possition

U8 LCD_pose_x_y(U8 x_pose,U8 y_pose)
{
	U8 local_adress;
	U8 error_state=0;
	if((x_pose<2)&& (y_pose<16))
	{
	 if(x_pose==0)
	  {
       //location at first line
		local_adress = y_pose;
	   }
	else if(x_pose ==1)
	  {
	  	//location at second line
		local_adress= y_pose + 0x40;
	  }
	LCD_write_cmd(local_adress+128);
	}
	else
	{
		error_state=1;
	}
	 return error_state;
}

void LCD_write_special_character(U8 *pattern,U8 pattern_number,U8 x_pose,U8 y_pose)
{
U8 local_CGRAMADDRESS = 0;
U8 iterator;

//calculate the CGRAM address whose each block 8 bytes
local_CGRAMADDRESS = pattern_number*8;
LCD_write_cmd(local_CGRAMADDRESS+64);

// write pattern in CGRAM
for(iterator = 0;iterator<8;iterator++)
{
	 LCD_write_data(pattern[iterator]);

}
//go back to DDRAM to display patter
LCD_pose_x_y(x_pose,y_pose);


//display the pattern write in CGRAM
LCD_write_data(pattern_number);
}

//function to clear the lcd
void LCD_clear(void)
{
	LCD_write_cmd(0b00000001);
}




void LCD_write_no(U32 num){
	U8 rem,arr_index=0;
	U8 length = 0;
	U8 str[20];
	U8 str_2[20];
	if(num==0){
		str[arr_index]='0';
		arr_index++;
	}
	else{
		while(num!=0){
	rem=num%10;
	str[arr_index]=rem+'0';
	arr_index++;
	num=num/10;
	length++;
	}
		str[arr_index]='\0';
		reverse(str,length);
	}

}

void reverse(U8 *ptr,U8 length)
{
  U8 start = 0;
  U8 end = length-1;
  while(start<end)
  {

	  swap(&ptr[start],&ptr[end]);
	  start++;
	  end--;
  }

  LCD_write_string(ptr);
}
 void swap(U8 * start, U8 * end)
 {
	 int z=0;
	 z=*start;
	 *start=*end;
     *end=z;
 }


