/*
 * main.c
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

void main(void)
{	stepper_init();


	//stepper_init();
//stepper_rotate_anti_cw_full_step();
set_angle(90,clock_wise);

	while(1)
	{
		//stepper_rotate_cw_full_step();
		//_delay_ms(3000);
		//stepper_rotate_anti_cw_full_step();

	//stepper_rotate_cw_full_step();
//_delay_ms(3000);
//stepper_rotate_anti_cw_full_step();*/
	}



}
