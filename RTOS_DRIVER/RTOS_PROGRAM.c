/*
 * RTOS_PROGRAM.c
 *
 *  Created on: Nov 12, 2021
 *      Author: Ahmed Moataz
 */



#include"BIT_CALC.h"
#include"STD_TYPES.h"

#include "DIO_Interface.h"

#include"RTOS_interface.h"



 task arr[no_of_task];


//البريورتي هخليها هلي حسب رقم ال الاريي
// arr[0] كده دي كده اعلي اولويه وهكذا
void task_creation(u8 periority,u8 periodicity,void(*fptr)(void))
{

 arr [periority].periodicity = periodicity;

 arr[periority].ptr =fptr;

}

//انفذذ الفانكشن الي عليها الدور

//بتيجي كل تك تايم تلف علي التاسكات تشوف ايي الي المفرض يتنفذ وتنفذه
void scheduler(void)
{

for(u8 i=0;i<no_of_task;i++)
{

if (tick_count%arr[i].periodicity==0)
arr[i].ptr();

}

}

//*****************************************************sec 2 *************************
void task_delete(u8 periority)
{

	 arr[periority].ptr =((void *)0);//العنوان دا بيشاور علي زيرو يعني مش حاجه بيشاور عليها null




}



void task_suspend(u8 periority)
{



}


void task_resume(u8 periority)
{



}


void task_delay(u8 periority, delay_val)

{



}


