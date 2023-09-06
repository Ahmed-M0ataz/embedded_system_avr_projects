/*
 * stepper_program.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Ahmed Moataz
 */

#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include "stepper_interface.h"


void stepper_rotate_cw_full_step(void)//cw clock wise
{
	DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
	DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
	DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
	DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
_delay_ms(num_delay);//time= 1/100
	    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		_delay_ms(num_delay);//time= 1/100

	    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
		DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		_delay_ms(num_delay);//time= 1/100

	    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
}


void stepper_rotate_anti_cw_full_step(void)//anti cw clock wise
{
	DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
	DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
	DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
	DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
_delay_ms(10);//time= 1/100
	    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		_delay_ms(10);//time= 1/100

	    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
		DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		_delay_ms(10);//time= 1/100

	    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
}


void stepper_rotate_cw_half_step(void)//cw clock wise
{
	DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
	DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
	DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
	DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
_delay_ms(10);//time= 1/100
	    DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		_delay_ms(10);//time= 1/100

	    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		_delay_ms(10);//time= 1/100

	    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
		DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		_delay_ms(10);//time= 1/100

		DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
			DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
			DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
			DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
		_delay_ms(10);//time= 1/100
			    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
				DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
				_delay_ms(10);//time= 1/100



			    DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
				_delay_ms(10);//time= 1/100
				DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
				DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
}

void stepper_rotate_anti_cw_half_step(void)//cw clock wise
{

	DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
		DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
		DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
	_delay_ms(10);//time= 1/100
		    DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
			DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
			DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
			DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
			_delay_ms(10);//time= 1/100

		    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
			DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
			DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
			DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
			_delay_ms(10);//time= 1/100

		    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
			DIO_set_pin_value(stepper_port,coil_yellow,DIO_High);
			DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
			DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
			_delay_ms(10);//time= 1/100


			DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
				DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
				DIO_set_pin_value(stepper_port,coil_blue,DIO_Low);
			_delay_ms(10);//time= 1/100
				    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_pink,DIO_High);
					DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
					_delay_ms(10);//time= 1/100

				    DIO_set_pin_value(stepper_port,coil_orange,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_blue,DIO_High);
					_delay_ms(10);//time= 1/100

				    DIO_set_pin_value(stepper_port,coil_orange,DIO_High);
					DIO_set_pin_value(stepper_port,coil_yellow,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_pink,DIO_Low);
					DIO_set_pin_value(stepper_port,coil_blue,DIO_High);



}

void set_angle(U32 angle,U8 direction)

{

	U32 steps=((angle * num_steps_for_complite_iteration_360)/360)/one_step; //full steppes

	if(direction == clock_wise)
	{
		for(U32 i =0 ; i < steps; i++)
		{
			stepper_rotate_cw_full_step();

		}


	}else
	{
		for(U32 i =0 ; i < steps; i++)
				{
					stepper_rotate_anti_cw_full_step();

				}


	}


}

void stepper_init(void)
{

DIO_set_pin_direction(stepper_port,coil_blue,DIO_Output);
DIO_set_pin_direction(stepper_port,coil_pink,DIO_Output);
DIO_set_pin_direction(stepper_port,coil_yellow,DIO_Output);
DIO_set_pin_direction(stepper_port,coil_orange,DIO_Output);


}
