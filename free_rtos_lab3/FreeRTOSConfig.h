/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <avr/io.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION		1//Ù‡Ø§Ø®Ø¯ Ù�ÙŠ Ø­Ø³Ø§Ø¨ÙŠ Ø§Ù„Ø§ÙˆÙ„ÙˆÙŠÙ‡ Ø¨ØªØ§Ø¹Øª ÙƒÙ„ Ù�Ø§Ù†ÙƒØ´Ù†
#define configUSE_IDLE_HOOK			0//Ù‡Ù†Ù�Ø° Ø­Ø§Ø¬Ù‡ ÙƒÙ„ Ù… Ø§ÙƒÙˆÙ† Ù�Ø§Ø¶ÙŠ
#define configUSE_TICK_HOOK			0 //1 code in every tick time is start Ù‡ÙŠØªÙ†Ù�Ø°
#define configCPU_CLOCK_HZ			( ( unsigned long ) 8000000 )//Ù‡Ø´ØªØºÙ„ Ø¹Ù„ÙŠ ÙƒØ±Ø³ØªØ§Ù„Ù‡ ÙƒØ§Ù…
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )//Ø§Ù„ØªÙŠÙƒ ØªØ§ÙŠÙ… Ø¨ØªØ§Ø¹ÙŠ 1 Ù…ÙŠÙ„ÙŠ (Ù‡Ù†Ø§ ÙƒØªØ¨Øª Ø¨Ø§Ù„Ù‡ÙŠØ±ØªØ²)
#define configMAX_PRIORITIES		( 4 )//Ø§Ø¹Ù„ÙŠ Ø¨Ø±ÙŠÙˆØ±ØªÙŠ Ù‡ØªÙƒÙˆÙ† Ù…ÙˆØ¬ÙˆØ¯Ù‡ Ù�ÙŠ Ø§Ù„ØªØ§Ø³ÙƒØ§Øª ÙˆØ§Ù„ Ø§Ù„Ø§Ø±ÙŠ Ø§Ùˆ Ø²ÙŠØ±Ùˆ Ø¯ÙŠ Ø§Ù‚Ù„ Ø¨Ø±ÙŠÙˆØ±ØªÙŠ
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 85 )//Ø¨ÙŠØ­Ø¯Ø¯ Ø­Ø¬Ù… Ø§Ù„Ø§Ø³ØªØ§Ùƒ Ø¨ØªØ§Ø¹Øª Ø§Ù„Ø§ÙŠØ¯ÙŠÙ„ ØªØ§Ø³Ùƒ ÙˆØ§Ù„85 Ø¯ÙŠ Ø§Ù‚Ù„ Ø­Ø§Ø¬Ù‡ Ø§Ù„Ù…Ù�Ø±ÙˆØ¶ Ø§Ø­Ø·Ù‡Ø§ Ù„Ù„Ø§ÙŠØ¯ÙŠÙ„ ØªØ§Ø³Ùƒ
#define configTOTAL_HEAP_SIZE		( (size_t ) ( 600 ) )//Ø§Ù„ÙƒÙ„ Ø§Ù„Ø³ÙŠØ²(Ø§Ù„Ø­Ø¬Ù…)Ø¨ØªØ§Ø¹ ÙƒÙ„ Ø§Ù„ØªØ§Ø³ÙƒØ§Øª Ø§Ù„ÙŠ Ø¹Ù†Ø¯ÙŠ Ø¨Ø§Ù„Ø¨Ø§ÙŠØª
#define configMAX_TASK_NAME_LEN		( 8 )//Ù…Ù…ÙƒÙ† ÙˆØ§Ù† Ø¨Ø¹Ù…Ù„ Ø§Ù„ØªØ§Ø³Ùƒ Ù…Ù…ÙƒÙ† Ø§Ø¯ÙŠÙ‡Ø§ Ø§Ø³Ù… ÙˆØ§Ù„Ø§Ø³Ù… Ø¯Ø§ Ø§Ø§ÙƒØ¨Ø± Ø±Ù‚Ù… Ø§ÙƒØªØ¨ Ø§Ù„Ø­Ø±ÙˆÙ� ÙˆØ§Ø¹Ù…Ù„ Ø­Ø³Ø§Ø¨ Ø§Ù„Ù†Ù„ ØªØ±Ù…Ù†ÙŠØªÙˆØ±
#define configUSE_TRACE_FACILITY	0 //Ù„Ùˆ Ø¹Ø§Ù…Ù„Ù‡Ø§ Ø¨ 1 Ù‡Ø¹Ø±Ù� Ø§Ø³ØªØ®Ø¯Ù…Ù‡Ø§ ÙŠØ¹Ù†ÙŠ Ù…Ù…ÙƒÙ† ØªØ§Ø®Ø¯ Ù…Ø¹Ù„ÙˆÙ…Ù‡ Ù…Ø¹ÙŠÙ†Ù‡ Ù…Ù† ØªØ§Ø³Ùƒ Ù…Ø¹ÙŠÙ† (Ø¨ØªØ±Ø§Ù‚Ø¨ Ø§Ù„ØªØ§Ø³ÙƒØ§Øª)(Ù…Ù…ÙƒÙ† Ø§Ø³ØªØ®Ø¯Ù…Ù‡Ø§ ÙˆØ§Ù†Ø§ Ø¨Ø¹Ù…Ù„ Ø¯ÙŠØ¨Ø¬)
#define configUSE_16_BIT_TICKS		1//Ù‡Ø¹Ø±Ù� Ø§Ù„Ø§Ø±ØªÙˆØ³ Ø¯Ø§ Ù‡ÙŠØ´ØªØºÙ„ Ø¹Ù„ÙŠ Ø§Ù†ÙŠ ØªØ§ÙŠÙ…Ø± Ù„Ùˆ Ø¨ 1 Ù‡Ø´ØªØºÙ„ Ø¹Ù„ÙŠ 16 Ø¨Øª Ø§Ù„ÙŠ Ù‡Ùˆ ØªØ§ÙŠÙ…Ø± 1 ÙˆÙ„Ùˆ Ø²ÙŠØ±Ùˆ Ù‡ÙŠØ´ØªØºÙ„ Ø¹Ù„ÙŠ 32 Ø¨Øª ÙˆØ§Ù†Ø§ Ø§ØµÙ„Ø§ Ù…Ø¹Ù†Ø¯ÙŠØ´ ØªØ§ÙŠÙ…Ø± 32 Ø¨Øª Ù� Ø§ÙƒÙŠØ¯ Ù‡Ø®Ù„ÙŠÙ‡Ø§ 1
#define configIDLE_SHOULD_YIELD		0
#define configQUEUE_REGISTRY_SIZE	0
#define configUSE_COUNTING_SEMAPHORES	1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		0
#define INCLUDE_uxTaskPriorityGet		0
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			0
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1


#endif /* FREERTOS_CONFIG_H */
