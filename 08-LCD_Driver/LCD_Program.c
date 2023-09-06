#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include"LCD_Cofiguration.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"

//******************************************study***********************
void send_command(u8 command)
{//rs low to write command
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_RS_Pin,DIO_Low);
	//rw low to write not read
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_RW_Pin,DIO_Low);
	//set command in pins
	DIO_SET_PORT_VALUE(LCD_Data_Port,command);
//final eneble the lcd to lcd know the data or command sent (pulse)
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_E_Pin,DIO_High);
	_delay_ms(2);
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_E_Pin,DIO_Low);

}
void send_data(u8 data)
{//rs low to write command
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_RS_Pin,DIO_High);
	//rw low to write not read
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_RW_Pin,DIO_Low);
	//set command in pins
	DIO_SET_PORT_VALUE(LCD_Data_Port,data);
//final eneble the lcd to lcd know the data or command sent (pulse)
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_E_Pin,DIO_High);
	_delay_ms(2);
	DIO_SET_PIN_VALUE(LCD_Control_Port,LCD_E_Pin,DIO_Low);

}
//*****************************************************************
void LCD_write_cmd(u8 cmd){
	DIO_set_pin_value(LCD_Control_Port,LCD_RS_Pin,DIO_Low);
	LCD_write(cmd);
}

void LCD_write_data(u8 data){
	DIO_set_pin_value(LCD_Control_Port,LCD_RS_Pin,DIO_High);
	LCD_write(data);
}

void LCD_write(u8 value){
	DIO_set_pin_value(LCD_Control_Port,LCD_RW_Pin,DIO_Low);
	for(int i=0;i<8;i++){
		DIO_set_pin_value(LCD_Data_Port,i,get_bit(value,i));//get bit for get each bit from byte cmd or data
	}
	DIO_set_pin_value(LCD_Control_Port,LCD_E_Pin,DIO_High); //pulse for know instruction is coming
	_delay_ms(1);											//pulse for know instruction is coming
	DIO_set_pin_value(LCD_Control_Port,LCD_E_Pin,DIO_Low);//pulse for know instruction is coming
}

void LCD_Intialization(void){
	DIO_set_port_direction(LCD_Data_Port,DIO_max_port_direction);
	DIO_set_pin_direction(LCD_Control_Port,LCD_RS_Pin,DIO_Output);
	DIO_set_pin_direction(LCD_Control_Port,LCD_RW_Pin,DIO_Output);
	DIO_set_pin_direction(LCD_Control_Port,LCD_E_Pin,DIO_Output);
	_delay_ms(40);
	LCD_write_cmd(0b00111000);
	_delay_us(50);
	LCD_write_cmd(0b00001100);
	_delay_us(50);
	LCD_write_cmd(0b00000001);
	_delay_ms(2);
}

u8 LCD_WRITE_POS(u8*Data,u8 x_pos,u8 y_pos){
	u8 error_stat=0; u8 local_address,frist_element=*Data,shifter,j=3;
	if ((x_pos<LCD_collom) &&( y_pos<LCD_row))
	{
		local_address= (x_pos + (y_pos*frist_address_in_row_two))|address_counter_move_carsor_command_datasheet;
		LCD_write_cmd(local_address);

		while(*Data!='\0')
		{if(local_address==LCD_max_collom_address)
		{
			local_address=LCD_frist_second_collom;
			LCD_write_cmd(local_address);}

		LCD_write_data(*Data);
		Data++;
		local_address++;


		}/*
		while(j!=0)//*Data !=frist_element
		{for(u8 i=1;i<12;i++)
		{
		Data=Data-i;
		shifter=*Data;
		if (i==1)
		{Data=Data+i;}// i num of element shift, 1 increase 1 to shift 1
		else {Data=Data+i-1;}
		*Data=shifter;
		LCD_write_data(*Data);
		}_delay_ms(500);
		j++;

		}*/

	}else {

		error_stat=1;
		return error_stat;}


}



u8 LCD_WRITE_num(u32 num,u8 x_pos,u8 y_pos)
{u8 rem, arr[20],arr_index=0;
	if (num==0)

{
	arr[arr_index];
		arr_index++;}
	while(num!=0)
	{

	rem= num%10;//to know the rakam 3asharat we a7ad we
	arr[arr_index]=rem+'0';//to know ascy for any char add num to ascy ((0)->48) ex know asccy num 5 -> (5+48=53)
	arr_index++;
	num = num /10;

	}arr[arr_index]='\0'//to out from the count;
	reverse(arr,arr_index);

		LCD_WRITE_POS(arr,x_pos,y_pos);



}
reverse(u8 *arr,u8 length)
{
u8 start=0;
u8 end=length-1;
while (start<end)
{
swap(&arr[start],&arr[end]);
start++;
end--;}

}

void swap (u8 *a,u8*b)
{
	u8 z =*a;
	*a=*b;
	*b=z;

}


