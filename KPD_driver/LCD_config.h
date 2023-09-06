/*
 * LCD_config.h
 *
 *  Created on: Sep 11, 2021
 *      Author: user
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//define control pin
#define LCD_control_port   Group_B
#define LCD_rs_pin         DIO_pin_A0
#define LCD_rw_pin         DIO_pin_A1
#define LCD_E_pin          DIO_pin_A2

//define data pin

#define LCD_data_port  Group_C
#define LCD_data_pin0  DIO_pin_D0
#define LCD_data_pin1  DIO_pin_D1
#define LCD_data_pin2  DIO_pin_D2
#define LCD_data_pin3  DIO_pin_D3
#define LCD_data_pin4  DIO_pin_D4
#define LCD_data_pin5  DIO_pin_D5
#define LCD_data_pin6  DIO_pin_D6
#define LCD_data_pin7  DIO_pin_D7

#endif /* LCD_CONFIG_H_ */
