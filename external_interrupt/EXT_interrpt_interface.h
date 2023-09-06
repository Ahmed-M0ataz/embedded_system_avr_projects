/*
 * EXT_interrpt_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Ahmed Moataz
 */

#ifndef EXT_INTERRPT_INTERFACE_H_
#define EXT_INTERRPT_INTERFACE_H_

#define INT_0 0
#define INT_1 1
#define INT_2 2
#define INT_0_E_BIT 6
#define INT_1_E_BIT 7
#define INT_2_E_BIT 5
#define INT_LOW_LEVEL 0b00
#define INT_logicale_change 0b01
#define INT_falling_edge 0b10
#define INT_rising_edge 0b11
#define INT_2_falling_edge 0b0
#define INT_2_rising_edge 0b1
#define bit_0_regester_MCUCR 0
#define bit_1_regester_MCUCR 1
#define bit_2_regester_MCUCR 2
#define bit_3_regester_MCUCR 3
#define bit_6_regester_MCUCSR 6
#define INT_global_BIT 7
#define INT_global_ENABLE 1
#define INT_global_DESABLE 0




void INT_ENABLE_SPECIFIC_SIE(u8 INT_index);
void INT_DISABLE(u8 INT_index);
void INT_SET_LEVEL(u8 INT_index,u8 INT_level);
void INT_GLOBAL(u8 INT_status);
set_call_back(u8 int_index,void (*ptr) (void));

#endif /* EXT_INTERRPT_INTERFACE_H_ */
