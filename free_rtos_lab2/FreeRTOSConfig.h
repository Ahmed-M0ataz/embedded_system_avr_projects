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

#define configUSE_PREEMPTION		1//هاخد في حسابي الاولويه بتاعت كل فانكشن
#define configUSE_IDLE_HOOK			0//هنفذ حاجه كل م اكون فاضي
#define configUSE_TICK_HOOK			0 //1 code in every tick time is start هيتنفذ
#define configCPU_CLOCK_HZ			( ( unsigned long ) 8000000 )//هشتغل علي كرستاله كام
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )//التيك تايم بتاعي 1 ميلي (هنا كتبت بالهيرتز)
#define configMAX_PRIORITIES		( 4 )//اعلي بريورتي هتكون موجوده في التاسكات وال الاري او زيرو دي اقل بريورتي
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 85 )//بيحدد حجم الاستاك بتاعت الايديل تاسك وال85 دي اقل حاجه المفروض احطها للايديل تاسك
#define configTOTAL_HEAP_SIZE		( (size_t ) ( 600 ) )//الكل السيز(الحجم)بتاع كل التاسكات الي عندي بالبايت
#define configMAX_TASK_NAME_LEN		( 8 )//ممكن وان بعمل التاسك ممكن اديها اسم والاسم دا ااكبر رقم اكتب الحروف واعمل حساب النل ترمنيتور
#define configUSE_TRACE_FACILITY	0 //لو عاملها ب 1 هعرف استخدمها يعني ممكن تاخد معلومه معينه من تاسك معين (بتراقب التاسكات)(ممكن استخدمها وانا بعمل ديبج)
#define configUSE_16_BIT_TICKS		1//هعرف الارتوس دا هيشتغل علي اني تايمر لو ب 1 هشتغل علي 16 بت الي هو تايمر 1 ولو زيرو هيشتغل علي 32 بت وانا اصلا معنديش تايمر 32 بت ف اكيد هخليها 1
#define configIDLE_SHOULD_YIELD		0
#define configQUEUE_REGISTRY_SIZE	0

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
