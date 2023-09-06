/*
 * EXT_interrpt_private.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Ahmed Moataz
 */

#ifndef EXT_INTERRPT_PRIVATE_H_
#define EXT_INTERRPT_PRIVATE_H_
//int ----> interrupt
#define MCUCR *((volatile u8*)0x55)//Raising edge or failling or change or... interrupt 0 and 1
#define MCUCSR *((volatile u8*)0x54)//Raising edge or failling or change or... interrupt 2
#define GICR *((volatile u8*)0x5B)//enable or disable for prepheral
#define GIFR *((volatile u8*)0x5A)//hard ware making flag bit 7 for int 1 bit 6 for int 0  bit 5 for int 2 (to i can remove flag 1 set bin 1  )
#define SREG *((volatile u8*)0x5F)//enable or disable for every prepherals  pit 7
void __vector_1(void)  __attribute__((signal));
void __vector_2(void)  __attribute__((signal));
void __vector_3(void)  __attribute__((signal));

//بقول للكومبيلر متمسحش الفانكشن دي عشان محدش بيندهاها في الميين انا عارف ان محدش بيندها وعاوزها موجوده عشان الهارد وير بينده signal
#endif /* EXT_INTERRPT_PRIVATE_H_ */
