/*
 * LCD_CONFIG.h
 *
 *  Created on: Sep 17, 2021
 *      Author: Ahmed Moataz
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
//COTROL PINS RS-RW-E
#define LCD_CONTROL_PORT GROUP_A
#define LCD_RS_PIN DIO_PIN_0
#define LCD_RW_PIN DIO_PIN_1
#define LCD_E_PIN DIO_PIN_2
//CONTROL PINS D0->D7
#define LCD_DATA_PORT GROUP_D
#define LCD_DATA_PIN_0 DIO_PIN_0
#define LCD_DATA_PIN_1 DIO_PIN_1
#define LCD_DATA_PIN_2 DIO_PIN_2
#define LCD_DATA_PIN_3 DIO_PIN_3
#define LCD_DATA_PIN_4 DIO_PIN_4
#define LCD_DATA_PIN_5 DIO_PIN_5
#define LCD_DATA_PIN_6 DIO_PIN_6
#define LCD_DATA_PIN_7 DIO_PIN_7


#endif /* LCD_CONFIG_H_ */
