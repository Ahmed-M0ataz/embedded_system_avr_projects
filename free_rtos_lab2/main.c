/*
 * main.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Z.50
 */


#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"



SemaphoreHandle_t xSemaphore;


// @ xSemaphoreTake()
// Setting xTicksToWait to portMAX_DELAY will cause the task to wait indefinitely
// (without timing out) provided INCLUDE_vTaskSuspend is set to 1 in FreeRTOSConfig.h.
void LED_1(void * pvParameters)
{

	u8 pushbutton;
	while(1)
	{
		xSemaphoreTake(xSemaphore,10);//10 افضل حاول 10 مرات عشان لو السيميفورمعمله تييك من حاجه تانيه
		DIO_GET_PIN_VALUE(GROUP_C,PIN0,&pushbutton);

		if(pushbutton == DIO_LOW)
		{
			xSemaphoreGive(xSemaphore);
		}
		vTaskDelay(200);
	}
}

void LED_2(void * pvParameters)
{
	static u8 state_2 = 0;
	while(1)
	{
		xSemaphoreTake(xSemaphore,portMAX_DELAY);
		DIO_SET_PIN_VALUE(GROUP_C,PIN1,toogle_bit(state_2,0));
//		if(state_2 == 1)
//		{
//			LCD_u8Write("LED2ON ",8,0);
//		}else
//		{
//			LCD_u8Write("LED2OFF",8,0);
//		}
		vTaskDelay(1000);
	}
}

void main(void)
{
	DIO_SET_PIN_DIRECTION(GROUP_C,PIN0,DIO_INPUT);
		DIO_SET_PIN_VALUE(GROUP_C,PIN0,DIO_OUTPUT);

		DIO_SET_PIN_DIRECTION(GROUP_C,PIN1,DIO_OUTPUT);

	// LED Pins
	

	// Push button Pin
	

	// LCD Pins
	

//	LCD_void_Initialize();

	xSemaphore = xSemaphoreCreateBinary();


	xTaskCreate(LED_1,"Task_1",150,NULL,1,NULL);
	xTaskCreate(LED_2,"Task_2",150,NULL,2,NULL);


	vTaskStartScheduler();

	while(1)
	{

	}
}
