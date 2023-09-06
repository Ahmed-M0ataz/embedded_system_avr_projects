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
//#include "LCD_interface.h"


SemaphoreHandle_t xSemaphore;


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	xSemaphoreGiveFromISR(xSemaphore,NULL);
}

// @ xSemaphoreTake()
// Setting xTicksToWait to portMAX_DELAY will cause the task to wait indefinitely
// (without timing out) provided INCLUDE_vTaskSuspend is set to 1 in FreeRTOSConfig.h.

void LED_2(void * pvParameters)
{

	while(1)
	{
		if(xSemaphoreTake(xSemaphore,10))
		{
	DIO_SET_PIN_VALUE(GROUP_C,PIN1,DIO_HIGH);
		//	LCD_u8Write("Button is pressed ",0,0);
		}else
		{	DIO_SET_PIN_VALUE(GROUP_C,PIN1,DIO_LOW);

			//LCD_u8Write("Button not pressed",0,0);
		}
	}
}

void main(void)
{
	// LED Pins
	DIO_SET_PIN_DIRECTION(GROUP_C,PIN1,DIO_HIGH);
	DIO_SET_PIN_DIRECTION(GROUP_D,PIN2,DIO_INPUT);
	DIO_SET_PIN_VALUE(GROUP_D,PIN2,DIO_HIGH);


	// LCD Pins
	

	// EXTI 0 Pin : Pin D2 -> I/P
	// Connect it to internal pull up resistor
	

	// EXTI 0 configurations
	MCUCR = 0b00000000;		// The falling edge of INT0 generates an interrupt request
	SREG  = 0b10000000;		// Global Interrupt Enable
	GICR  = 0b01000000;		// External Interrupt Request 0 Enable


//	LCD_void_Initialize();
//semaphore  take decrement , give increment

	xSemaphore = xSemaphoreCreateCounting(1,0);//1 max task  , 0 intiol task (if give make increment , take decrement

	xTaskCreate(LED_2,"Task_2",150,NULL,1,NULL);


	vTaskStartScheduler();

	while(1)
	{

	}
}



