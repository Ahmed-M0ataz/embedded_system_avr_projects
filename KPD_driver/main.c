/*
 * main.c
 *
 *  Created on: Sep 23, 2021
 *      Author: user
 */


#include"std_types.h"
#include"BIT_CALC.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"

void main(void)
{


	U32 local_key;

        for(int i=0;i<4;i++)
        {
    	DIO_set_pin_direction(Group_A,i,DIO_Output);
    	DIO_set_pin_value(Group_A,i,DIO_High);
        }

        for(int i=7;i>3;i--)
        {
        	DIO_set_pin_direction(Group_A,i,DIO_Input);
            DIO_set_pin_value(Group_A,i,DIO_High);
        }

       LCD_initial();

while(1)
{
  do
  {
	  local_key = KPD_GetPressedKey();
  }while(local_key == 0xff);


  LCD_write_no(local_key);

}
}
