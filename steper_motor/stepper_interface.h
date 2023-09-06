/*
 * stepper_interface.h
 *
 *  Created on: Sep 25, 2021
 *      Author: Ahmed Moataz
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define stepper_port Group_D
#define coil_blue DIO_pin_A0
#define coil_pink DIO_pin_A1
#define coil_yellow DIO_pin_A2
#define coil_orange DIO_pin_A3
#define clock_wise 0
#define num_steps_for_complite_iteration_360 2048
#define num_delay 10
#define anti_clock_wise 1

#define one_step 4 //dvide stepes/4
void stepper_rotate_cw_full_step(void);//cw clock wise
void stepper_rotate_anti_cw_full_step(void);//anti cw clock wise
void stepper_rotate_cw_half_step(void);//cw clock wise
void stepper_rotate_anti_cw_half_step(void);//cw clock wise
void set_angle(U32 angle,U8 direction);
void stepper_init(void);


#endif /* STEPPER_INTERFACE_H_ */
