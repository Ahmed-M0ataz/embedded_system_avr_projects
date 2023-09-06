/*
 * LCD_INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: Ahmed Moataz
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_WRITE_CMD(u8 cmd);
void LCD_WRITE_DATE(u8 DATA);
void LCD_WRITE(u8 VALUE);
void LCD_INIT(void);


#endif /* LCD_INTERFACE_H_ */
