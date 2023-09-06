/*
 * DIO_interface.h
 *
 *  Created on: Sep 10, 2021
 *      Author: user
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
//PORTS DEFINE
#define Group_A 0
#define Group_B 1
#define Group_C 2
#define Group_D 3

//DEFINE MAX AND MIN NUMBER OF PORT AND PINS
#define DIO_Max_port_NB 4
#define DIO_Max_pin_NB  8

//DEFINE DIRECTION OF PINS INPUT OR OUTPUT
#define DIO_Input 0
#define DIO_Output 1

//DEFINE VALUE OF PIN HIGH OR LOW (0 OR 1)
#define DIO_High 1
#define DIO_Low 0

//MAXIMUM VALUE OF PORT FROM 0 TO 255
#define DIO_Max_port_value 255

#define DIO_Min_port_direction 0
#define DIO_Max_port_direction 255

//DEFINE EACH PIN OF EACH PORT
#define DIO_pin_A0 0
#define DIO_pin_A1 1
#define DIO_pin_A2 2
#define DIO_pin_A3 3
#define DIO_pin_A4 4
#define DIO_pin_A5 5
#define DIO_pin_A6 6
#define DIO_pin_A7 7

#define DIO_pin_B0 0
#define DIO_pin_B1 1
#define DIO_pin_B2 2
#define DIO_pin_B3 3
#define DIO_pin_B4 4
#define DIO_pin_B5 5
#define DIO_pin_B6 6
#define DIO_pin_B7 7

#define DIO_pin_C0 0
#define DIO_pin_C1 1
#define DIO_pin_C2 2
#define DIO_pin_C3 3
#define DIO_pin_C4 4
#define DIO_pin_C5 5
#define DIO_pin_C6 6
#define DIO_pin_C7 7


#define DIO_pin_D0 0
#define DIO_pin_D1 1
#define DIO_pin_D2 2
#define DIO_pin_D3 3
#define DIO_pin_D4 4
#define DIO_pin_D5 5
#define DIO_pin_D6 6
#define DIO_pin_D7 7


//FUNCTION PROTOTYPE WHICH IMPLEMENT IN PROGRAME.C
U8 DIO_set_pin_value(U8 port_NB,U8 pin_NB,U8 pin_value );
U8 DIO_set_pin_direction(U8 port_NB,U8 pin_NB,U8 pin_direction);
U8 DIO_set_port_value(U8 port,U8 port_value);
U8 DIO_set_port_direction(U8 port_NB, U8 port_direction);
U8 DIO_get_pin_value(U8 port_NB,U8  pin_NB,U8 * pin_value);
U8 DIO_get_port_value(U8 port_NB,U8 * port_value);

#endif /* DIO_INTERFACE_H_ */
