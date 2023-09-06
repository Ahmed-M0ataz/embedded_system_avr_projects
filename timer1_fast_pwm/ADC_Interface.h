/*
 * ADC_Interface.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed Moataz
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define LIFT_ADJUST_10BIT 5
#define REFRENCE_VOLT_BIT7 7
#define REFRENCE_VOLT_BIT6 6
#define ADC_FLAG_BIT 4

#define ADC_BIT_enable 7
#define ADC_CH_0 0
#define ADC_CH_1 1
#define ADC_CH_2 2
#define ADC_CH_3 3
#define ADC_CH_4 4
#define ADC_CH_5 5
#define ADC_CH_6 6
#define ADC_CH_7 7
#define refrance_volt 5.0
#define resolution 1024.0

void ADC_INT(void);

u16 ADC_READ(u8 channel);


#endif /* ADC_INTERFACE_H_ */
