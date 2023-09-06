/*
 * program.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Ahmed Moataz
 */
#include"BIT_CALC.h"
#include"STD_TYPES.h"
#include "DIO_Configuration.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "kpd_interface.h"


u8 kpd_col_pins[kpd_col]={DIO_Pin_0,DIO_Pin_1,DIO_Pin_2,DIO_Pin_3};
u8 kpd_row_pins[kpd_row]={DIO_Pin_4,DIO_Pin_5,DIO_Pin_6,DIO_Pin_7};

void kpd_get_state(u8 kpd_status[kpd_no_keys])
 {
	 u8 col_index,row_index,pin_value,key_index;

	 for(col_index=0;col_index<kpd_col;col_index++)
	 {
		 DIO_set_pin_value(kpd_col_port,kpd_col_pins[col_index],DIO_Low);
		 for (row_index=0;row_index<kpd_row;row_index++)
		 {
			 DIO_get_pin_value(kpd_row_port,kpd_row_pins[row_index],&pin_value);
			 key_index= col_index + (row_index * kpd_col);
			 if(pin_value==DIO_High)
			 {
				 kpd_status[key_index]= kpd_not_pressed;



			 }else 				 kpd_status[key_index]= kpd_pressed;


		 }

		 DIO_set_pin_value(kpd_col_port,kpd_col_pins[col_index],DIO_High);
	 }


 }

void kpd_set_init(void)
{ u8 col_index,row_index;
for(col_index=0;col_index<kpd_col;col_index++)
	 {
		DIO_set_pin_direction(kpd_col_port,kpd_col_pins[col_index],DIO_Output);
	 }
for (row_index=0;row_index<kpd_row;row_index++)
		 {

	DIO_set_pin_direction(kpd_row_port,kpd_row_pins[row_index],DIO_Input);
	DIO_set_pin_value(kpd_row_port,kpd_row_pins[row_index],DIO_High);


		 }

}
