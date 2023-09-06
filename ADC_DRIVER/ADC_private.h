/*
 * ADC_private.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed Moataz
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX *((volatile u8*)0x27) // (u8 * is acasting but (admux *) is a derefrance
#define ADCSRA *((volatile u8*)0x26)
#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)
#define SFIOR *((volatile u8*)0x50)

#endif /* ADC_PRIVATE_H_ */
