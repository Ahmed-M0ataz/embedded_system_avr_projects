/*
 * config.h
 *
 *  Created on: Sep 22, 2021
 *      Author: user
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_port  Group_A

#define KBD_column_pin0    DIO_pin_C0
#define KBD_column_pin1    DIO_pin_C1
#define KBD_column_pin2    DIO_pin_C2
#define KBD_column_pin3    DIO_pin_C3

#define KBD_row_pin0    DIO_pin_C4
#define KBD_row_pin1    DIO_pin_C5
#define KBD_row_pin2    DIO_pin_C6
#define KBD_row_pin3    DIO_pin_C7



#define KPD_no_pressed_key  0
#define KBD_Arr_Value   {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#endif /* KPD_CONFIG_H_ */
