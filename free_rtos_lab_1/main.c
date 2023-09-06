/*
 * main.c
 *
 *  Created on: Dec 3, 2021
 *      Author: Ahmed Moataz
 */

#include"FreeRTOS.h"
#include"task.h"

#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"

//#include"LCD_Interface.h"

void LED_1 (void *pvpesament)
{
static u8 state_1=0;
	while(1)//عشان لما ييجي رجع للمكان الي كان فيه بعد الديلي يعمل لوب وينفذ الاكشن الي عاوز انفذه تاني
	{	DIO_SET_PIN_VALUE(GROUP_C,PIN0,toogle_bit(state_1,0));
		vTaskDelay(1000);//دا الوقت الي عاوز كل تاسكايه تتنفذ بعديه (peredisty)
//ولو لما بودي التاسك ويتينج بعمل سيف للمكان الي كنت فيه ولما باجي انديها تاني هيرجع عند المكان الي سبته فيه
}
}
void LED_2 (void *pvpesament)
{
static u8 state_2=0;
while(1)//عشان لما ييجي رجع للمكان الي كان فيه بعد الديلي يعمل لوب وينفذ الاكشن الي عاوز انفذه تاني
	{	DIO_SET_PIN_VALUE(GROUP_C,PIN1,toogle_bit(state_2,0));
		vTaskDelay(2000);//دا الوقت الي عاوز كل تاسكايه تتنفذ بعديه (peredisty)

}
}
void LED_3 (void *pvpesament)//لازم اكتب كده
{
static u8 state_3=0;
while(1)//عشان لما ييجي رجع للمكان الي كان فيه بعد الديلي يعمل لوب وينفذ الاكشن الي عاوز انفذه تاني
	{	DIO_SET_PIN_VALUE(GROUP_C,PIN2,toogle_bit(state_3,0));
		vTaskDelay(3000);//دا الوقت الي عاوز كل تاسكايه تتنفذ بعديه (peredisty)

}
}



void main (void)
{
	DIO_SET_PIN_DIRECTION(GROUP_C,PIN0,DIO_HIGH);
	DIO_SET_PIN_DIRECTION(GROUP_C,PIN1,DIO_HIGH);
	DIO_SET_PIN_DIRECTION(GROUP_C,PIN2,DIO_HIGH);

	xTaskCreate(LED_1,"TASK_1",85,NULL,1,NULL);//FRIST NAME FUNC , 2- NAME TASK (BETWEEN "") ,3- LENGH OF BYTE كام بايت هتاخدها التاسك دي , IF لو معنديش انبوت هبعت نال لو عندي اينبوت للفانكشن هبعت عنوان الفاريبول الي انيوت للفانكشن(ر&ي)
//5-   البريورتي بتاعت التاسك (اعلي بريورتي أعلي رقم عندي ) ولو عندي 5 تاسك ف اعلي بريورتي هنا هزود واحد ويبقي 6
//6-بوينتر بيشاور علي التاسكايه الي كريتها لو مش عاوز هكتب NULL

	xTaskCreate(LED_2,"TASK_1",85,NULL,2,NULL);

	xTaskCreate(LED_3,"TASK_1",85,NULL,3,NULL);

	vTaskStartScheduler();//بقوله ابدا شغل
}




