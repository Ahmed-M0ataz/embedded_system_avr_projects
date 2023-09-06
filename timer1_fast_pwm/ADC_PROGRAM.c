/*
 * ADC_PROGRAM.c

 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed Moataz
 */



#include"BIT_CALC.h"
#include"STD_TYPES.h"
#include "ADC_private.h"
#include "ADC_Interface.h"


void ADC_INT(void)
{
	set_bit(ADCSRA,2);//(prescalas =128) اقل تردد ممكن اشتغل بيه بقسم ال 8000000علي 128 وهو الي بيعمل كده
	set_bit(ADCSRA,1);//(prescalas =128) اقل تردد ممكن اشتغل بيه بقسم ال 8000000علي 128 وهو الي بيعمل كده
	set_bit(ADCSRA,0);//(prescalas =128) اقل تردد ممكن اشتغل بيه بقسم ال 8000000علي 128 وهو الي بيعمل كده

	clear_bit(ADMUX,REFRENCE_VOLT_BIT7);//refrance volt 5v avcc
	set_bit(ADMUX,REFRENCE_VOLT_BIT6);//refrance volt 5v avcc
	set_bit(ADMUX,LIFT_ADJUST_10BIT);//left adjustment
	set_bit(ADCSRA,ADC_BIT_enable);//adc enable
}

u16 ADC_READ(u8 channel)//تعبر عن ال بن chanal
{

	ADMUX &=0b11100000; //ال الأند مع الواحد هحافظ علي اول تلات بتات الي هما الخاصين الكونفجريشن الي اول بتين بالرفرنس فولت والتالته بتاعت الليفت والاند مع الزيرو بيصفر كل حاجه
ADMUX |=channel;//اوور عشان احط الإتشنل الي هو عاوزها وكده كده بيتحطو في اول 5 بت
set_bit(ADCSRA,6);//start conv

while (get_bit(ADCSRA,ADC_FLAG_BIT)==0);//طول ما الفلاج ب زيرو خليك لووب هنا لو بقي ب واحد اخرج من اللوب
//set_bit(ADCSRA,4);
//u16 res=ADCH;
//res= (res<<2)|(ADCL>>6);
u16 res=(ADCL>>6);
res|= (ADCH<<2);
return res;

}
