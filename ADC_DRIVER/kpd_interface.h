/*
 * kpd_interface.h
 *
 *  Created on: Sep 24, 2021
 *      Author: Ahmed Moataz
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define kpd_no_keys 16
#define kpd_col 4
#define kpd_row 4
 #define kpd_col_port Group_A
 #define kpd_row_port Group_A
 #define kpd_pressed 1
#define kpd_not_pressed 0
void kpd_get_state(u8 kpd_status[kpd_no_keys]);
void kpd_set_init(void);
void show_num_on_lcd_keypad(u8 arr[kpd_no_keys],u8 *count);
void all_col_high(void);
/***********************************************study************************************************/
u8 kpd_pressed_key(void);
//u8 kpd_pressed_key(u8 arr[rows_num][colloms_num]);

#endif /* KPD_INTERFACE_H_ */
