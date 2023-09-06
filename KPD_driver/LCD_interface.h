/*
 * LCD_interface.h
 *
 *  Created on: Sep 11, 2021
 *      Author: user
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_write_cmd(U8 cmd);

void LCD_write_data(U8 data);

void LCD_write(U8 value);

void LCD_initial(void);
void LCD_write_string (const char *);
U8 LCD_pose_x_y(U8 x_pose,U8 y_pose);
void LCD_write_special_character(U8 *pattern,U8 pattern_number,U8 x_pose,U8 y_pose);
void LCD_clear(void);
void LCD_write_no(U32 num);
void reverse(U8 *ptr,U8 length);
void swap(U8 * start, U8 * end);

#endif /* LCD_INTERFACE_H_ */
