/*
 * uart_private.h
 *
 *  Created on: Oct 30, 2021
 *      Author: Ahmed Moataz
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)//config boud rate
#define UBRRH *((volatile u8*)0x40)//config boud rate













#endif /* UART_PRIVATE_H_ */
