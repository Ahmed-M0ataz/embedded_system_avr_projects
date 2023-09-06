/*
 * kpd_config.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Ahmed Moataz
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

 #define kpd_no_pressed_key 0xff //255 ->0b111111111
#define rows_num 4
#define colloms_num 4
#define kpd_collom_0_pin DIO_Pin_0
#define kpd_collom_1_pin DIO_Pin_1
#define kpd_collom_2_pin DIO_Pin_2
#define kpd_collom_3_pin DIO_Pin_3

#define kpd_row_0_pin DIO_Pin_4
#define kpd_row_1_pin DIO_Pin_5
#define kpd_row_2_pin DIO_Pin_6
#define kpd_row_3_pin DIO_Pin_7


//#define kpd_arr_impli {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}//impli-> implimentation
#define kpd_arr_implimentation { {1,2,3,'+'},{'C',0,'=','/'},{7,8,9,'*'},{4,5,6,'-'} }//impli-> implimentation
//*********************************why (4,5,6,-)  replace with (c,0,=,/)**************************important************
#endif /* KPD_CONFIG_H_ */
