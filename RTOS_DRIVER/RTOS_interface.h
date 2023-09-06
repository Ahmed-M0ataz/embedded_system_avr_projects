/*
 * RTOS_interface.h
 *
 *  Created on: Nov 12, 2021
 *      Author: Ahmed Moataz
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_





typedef struct{
	u8 periodicity;
	//u8 frist_delay;
	void (*ptr)(void);//pointer to function


}task;

/*typedef struct{
	u8 periodicity;
	//u8 frist_delay;
	void (*ptr)(void);//pointer to function
	u8 task_state;

}task_sec2;*/
#define no_of_task 3 //هنا بحدد كام تاسك هكريت الي هحطها في الاري
//global varible intial =0
u8 tick_count;//لما التايمر يقولي ان عدي ثانيه المفروض ازود هنا واحد


//#define Lno_of_task 3
//task arr[no_of_task];



void task_creation(u8 periority,u8 periodicity,void(*fptr)(void));

void scheduler(void);


#endif /* RTOS_INTERFACE_H_ */
