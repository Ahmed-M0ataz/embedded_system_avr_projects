#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include"DIO_Interface.h"

void main(void){
	DIO_set_pin_direction(Group_D,DIO_Pin_0,DIO_Input);
	DIO_set_pin_value(Group_D,DIO_Pin_0,DIO_High);
	DIO_set_pin_direction(Group_D,DIO_Pin_1,DIO_Output);
	u8 result;
	while(1){
		DIO_get_pin_value(Group_D,DIO_Pin_0,&result);
		if(result==0){
			DIO_set_pin_value(Group_D,DIO_Pin_1,DIO_High);
		}else{
			DIO_set_pin_value(Group_D,DIO_Pin_1,DIO_Low);
		}
	}
}
