/*
 * i2c_program.c
 *
 *  Created on: Nov 6, 2021
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
#include"i2c_private.h"

#include"i2c_interface.h"


void i2c_init_master(void)
{

	TWSR=0b00000000;//bit 0 and 1 config freq
	TWBR=192;//config freq

}


void i2c_start(void)
{

	TWCR=0b10100100;//start next operation ,start condition, enable i2c , enable interupt flag (disable)

	while (get_bit(TWCR,7)==0);








}


void i2c_master_transmit_data(u8 data)
{
TWDR=data;
TWCR=0b10000100;//bit 7 start next operation and make flag =0, bit 2 enable i2c
while (get_bit(TWCR,7)==0);


}

void i2c_master_transmit_address(u8 address)
{
TWDR=address;
TWCR=0b10000100;//bit 7 start next operation and make flag =0, bit 2 enable i2c
while (get_bit(TWCR,7)==0);


}




u8 i2c_master_receive_ack(void)
{
	TWCR=0b11000100; //bit6 اول مبعمل ريسيف برد بقول تمام اكنولدج
	while (get_bit(TWCR,7)==0);

return TWDR;
}


u8 i2c_master_receive_not_ack(void)
{
	TWCR=0b10000100; //bit6 اول مبعمل ريسيف برد بقول مش تمام مش اكنولدج
	while (get_bit(TWCR,7)==0);

return TWDR;
}


void i2c_stop(void)
{//data sheet page 175
	TWCR=0b10010100;//start next operation ,bit 4 stop condition, enable i2c , enable interupt flag (disable)

		while (get_bit(TWCR,4)==1);//هو لما بيخلص بيصفر البتايه لوحده


}



//*********************************************slave****************************************








void i2c_init_slave(u8 slave_address)
{

	TWAR=slave_address;
	TWCR=0b11000100;//bit 7 خد بالك لو حد كلمك وبعتلك عنوانك, bit 6 acnoledg, bit 3 enable i2c



}

//متخرجش منها غير لما حد يكلمني
void i2c_listen(void)
{
	while (get_bit(TWCR,7)==0);

}


void i2c_slave_transmit_data(u8 data)
{
TWDR=data;
TWCR=0b10000100;//bit 7 start next operation and make flag =0, bit 2 enable i2c
while (get_bit(TWCR,7)==0);


}


u8 i2c_slave_receive_ack(void)
{
	TWCR=0b11000100; //bit6 اول مبعمل ريسيف برد بقول تمام اكنولدج
	while (get_bit(TWCR,7)==0);

return TWDR;
}


u8 i2c_slave_receive_not_ack(void)
{
	TWCR=0b10000100; //bit6 اول مبعمل ريسيف برد بقول مش تمام مش اكنولدج
	while (get_bit(TWCR,7)==0);

return TWDR;
}




















