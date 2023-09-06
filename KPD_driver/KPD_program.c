/*
 * program.c
 *
 *  Created on: Sep 22, 2021
 *      Author: user
 */

#include "std_types.h"
#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

U8 KPD_GetPressedKey(void)
{

	U8 Press_key = KPD_no_pressed_key ;
	U8 column;
	U8 row;
	U8 pin_state;
    static U8 KBD_Arr[Row_NB][Column_NB] = KBD_Arr_Value;
    static U8 Arr_Column[Column_NB] = {KBD_column_pin0 ,KBD_column_pin1 ,KBD_column_pin2 ,KBD_column_pin3 };
    static U8 Arr_Row[Row_NB] = {KBD_row_pin0 ,KBD_row_pin1 ,KBD_row_pin2 ,KBD_row_pin3};

    for(column=0;column<Column_NB;column++)
    {
       DIO_set_pin_value(KPD_port,Arr_Column[column],DIO_Low);


       for(row=0;row<Row_NB;row++)
       {
    	  DIO_get_pin_value(KPD_port,Arr_Row[row],&pin_state);

       if(DIO_Low == pin_state)
       {
    	   Press_key =  KBD_Arr[row][column];

    	   while( DIO_Low == pin_state)
    	   {

    		   DIO_get_pin_value(KPD_port,Arr_Row[row],&pin_state);
    	   }

    	   return Press_key;
       }

       }

       DIO_set_pin_value(KPD_port,Arr_Column[column],DIO_High);
    }


	return Press_key;
}



