/*
 * spi_program.c
 *
 *  Created on: Nov 5, 2021
 *      Author: Ahmed Moataz
 */


#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include"LCD_Cofiguration.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"
#include"spi_Private.h"
#include"spi_Interface.h"



void spi_init_master(void)
{

//spi interrupt disable  (FLAG AFTER TRANSMITION)
//spi enable
	//msb frist  هبدا ابعت من الب ال7 يبقي موست ولو هبدا ابعت من البت ال0 يبقي ليييست
	//master mode شغال ماستر موود مش اسليف
	//SCK is low when idle

	//cpol=0,cpha=0  • Bit 3 – CPOL: Clock Polarity  When CPOL is written to zero,
/*
 * • Bit 2 – CPHA: Clock Phase
The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading
(first) or trailing (last) edge of SCK.
 * يعني لما تيجي رايزنج هبعت البتايه ولما ييجي الفولنج هستقبل البتايه
 //هشغل الفيز ونفس البولرتي
 */





	//PRESCALER=16//bit 0and 1

SPCR=0b01010001;

}

void spi_init_slave(void)
{

//spi interrupt disable  (FLAG AFTER TRANSMITION)
//spi enable
	//msb frist  هبدا ابعت من الب ال7 يبقي موست ولو هبدا ابعت من البت ال0 يبقي ليييست
	//slave mode شغال اسليف موود مش ماستر
	//SCK is low when idle

	//cpol=0,cpha=0  • Bit 3 – CPOL: Clock Polarity  When CPOL is written to zero,
/*
 * • Bit 2 – CPHA: Clock Phase
The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading
(first) or trailing (last) edge of SCK.
 * يعني لما تيجي رايزنج هبعت البتايه ولما ييجي الفولنج هستقبل البتايه
 //هشغل الفيز ونفس البولرتي
 */





	//كده كده انا باخد الكلوكايه من الماستر

SPCR=0b01000000;

}



u8 spi_transfer(u8 data)
{
	//اول م بحط الداتا في الرجستر دا كده بقوله ابدا ابعت واول مبيبعت بيستقبل ف نفس الكلوكايه
SPDR=data;//الرجستر الي أنا ببعت من عليه

while (get_bit(SPSR,7)==0);//البتايه الخاصه ان بترفعلي الفلاج الي بيقولي ان الإرسال خلص





return SPDR;
}












