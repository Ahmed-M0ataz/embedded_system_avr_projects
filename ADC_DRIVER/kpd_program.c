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
#include "kpd_config.h"


u8 kpd_col_pins[kpd_col]={DIO_Pin_0,DIO_Pin_1,DIO_Pin_2,DIO_Pin_3};
u8 kpd_row_pins[kpd_row]={DIO_Pin_4,DIO_Pin_5,DIO_Pin_6,DIO_Pin_7};



//*************************study***************************************************************

u8 kpd_pressed_key(void)
{
	//arr[rows_num][colloms_num]=kpd_arr_impli;//static save in .data
	static u8 arr[rows_num][colloms_num]=kpd_arr_implimentation;//static save in .data  كل زرار عاوزه حاجه معينه ف أكتبه في الإمبليمنتيشن
	static u8 collom_arr[colloms_num]={kpd_collom_0_pin,kpd_collom_1_pin,kpd_collom_2_pin,kpd_collom_3_pin};
	static u8 row_arr[rows_num]={kpd_row_0_pin,kpd_row_1_pin,kpd_row_2_pin,kpd_row_3_pin};

	u8 pressed_key=kpd_no_pressed_key, collom_index,row_index,pin_state;//the key is pressed

	for(collom_index=0;collom_index<colloms_num;collom_index++)
	{
		//activate currant collom
		DIO_set_pin_value(kpd_col_port,collom_arr[collom_index],DIO_Low);

		for(row_index=0;row_index<rows_num;row_index++)
		{
			/*read currant row*/
			DIO_get_pin_value(kpd_col_port,row_arr[row_index],&pin_state);//read currant row
			/*check key pressed	*/
			if(pin_state==DIO_Low)
			{
				pressed_key=arr[row_index][collom_index];
				//to solve polling pusy waiting untill event عشان لو فضلت دايس علي الزرار untill key is released
				while(pin_state==DIO_Low)
				{
					DIO_get_pin_value(kpd_col_port,row_arr[row_index],&pin_state);//read currant row
				}
				return pressed_key;

			}
		}
		/*de activate currant collom*/
		DIO_set_pin_value(kpd_col_port,collom_arr[collom_index],DIO_High);

	}


return pressed_key;
}



//*************************************************************************************************
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
{ u8 col_index;u8 row_index;
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



void show_num_on_lcd_keypad(u8 arr[kpd_no_keys],u8 *count)

{





			if (arr[0]==kpd_pressed)
			{
				LCD_WRITE_num(1,*count,0);

				*count++;
			}
			else if (arr[1]==kpd_pressed)
			{
				LCD_WRITE_num(2,*count,0);
						*count++;
			}
			else if (arr[2]==kpd_pressed)
				{
					LCD_WRITE_num(3,*count,0);
							*count++;
				}
			else if (arr[4]==kpd_pressed)
				{
					LCD_WRITE_num(4,*count,0);
							*count++;
				}
			else if (arr[5]==kpd_pressed)
				{
					LCD_WRITE_num(5,*count,0);
							*count++;
				}
			else if (arr[6]==kpd_pressed)
				{
					LCD_WRITE_num(6,*count,0);
							*count++;
				}
			else if (arr[8]==kpd_pressed)
				{
					LCD_WRITE_num(7,*count,0);
							*count++;
				}
			else if (arr[9]==kpd_pressed)
				{
					LCD_WRITE_num(8,*count,0);
							*count++;
				}
			else if (arr[10]==kpd_pressed)
					{
						LCD_WRITE_num(9,*count,0);
								*count++;
					}
			else if (arr[13]==kpd_pressed)
					{
						LCD_WRITE_num(0,*count,0);
								*count++;
					}






}
void all_col_high(void)
{
	 DIO_set_pin_value(kpd_col_port,kpd_col_pins[0],DIO_High);
			 DIO_set_pin_value(kpd_col_port,kpd_col_pins[1],DIO_High);
			 DIO_set_pin_value(kpd_col_port,kpd_col_pins[2],DIO_High);
			 DIO_set_pin_value(kpd_col_port,kpd_col_pins[3],DIO_High);

}
