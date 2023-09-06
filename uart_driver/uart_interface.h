/*
 * uart_interface.h
 *
 *  Created on: Oct 30, 2021
 *      Author: Ahmed Moataz
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init(void);

void UART_SEND_CHAR(u8 data);
u8 UART_RECEIVE_CHAR(void);//char 1 byte عشان انا عملت كونفيج انها تبعت 8 بت

void UART_SEND_STRING(u8 *str);
void UART_RECEIVE_STRING(u8 *str);

#endif /* UART_INTERFACE_H_ */
