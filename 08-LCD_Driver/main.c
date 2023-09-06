#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include"LCD_Cofiguration.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"
void main (void){
	LCD_Intialization();

	//LCD_Intialization();
	/*LCD_write_cmd(0b10000101);//shift the write on lcd (0b1)is (standard ddram) and after write address in vesable ddram 0->15
	LCD_write_data('m');
	LCD_write_data('o');
	LCD_write_data('a');
	LCD_write_data('t');
	LCD_write_data('a');
	LCD_write_data('z');*/



	//set cgram  to write symbles not keyboard
	/*char i;
	LCD_Intialization();
		LCD_write_cmd(0b01000000);
		char charb[]={0, 0, 0, 0, 7, 1, 31, 0};
		char chara[]={0, 3, 2, 7, 0, 2, 2, 2};
		char charc[]={0, 0, 0, 0, 0, 28, 20, 28};
		char chard[]={0, 0, 0, 0, 0, 4, 4, 28};
	for (i=0;i<8;i++)
	{

		LCD_write_data(chard[i]);


	}
	for (i=0;i<8;i++)
		{

			LCD_write_data(charc[i]);


		}
	for (i=0;i<8;i++)
		{

			LCD_write_data(charb[i]);


		}
	for (i=0;i<8;i++)
		{

			LCD_write_data(chara[i]);


		}
	LCD_write_cmd(0b10000000);
	LCD_write_data(0);// 0 is frist block in cgram to 8
	LCD_write_data(1);
	LCD_write_data(2);LCD_write_data(3);*/

	//**********write string*****
	//u8 arr[]="ahmedmoataz";
	LCD_WRITE_POS("ahmedmoataz",0,0);//write string on lcd send string and pos x and pos y
	//LCD_WRITE_num(5482,0,0);

	while(1){}
}
