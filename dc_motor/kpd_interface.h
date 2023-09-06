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


#endif /* KPD_INTERFACE_H_ */
