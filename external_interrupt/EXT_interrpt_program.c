/*
 * program.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Ahmed Moataz
 */


#include"BIT_CALC.h"
#include"STD_TYPES.h"
#define F_CPU 8000000
#include"avr/delay.h"
#include "DIO_Interface.h"
#include "EXT_interrpt_private.h"
#include "EXT_interrpt_interface.h"

void (*pvoid_callback[3]) (void);

//enable  for prepheral
void INT_ENABLE_SPECIFIC_SIE(u8 INT_index)
{
	switch (INT_index)
	{
	case INT_0:
	set_bit(GICR,INT_0_E_BIT);//external interrupt pin 0
	break;
	case INT_1:
		set_bit(GICR,INT_1_E_BIT);//external interrupt pin 1
		break;
	case INT_2:
		set_bit(GICR,INT_2_E_BIT);//external interrupt pin 2
		break;
	}

}

// disable for prepheral
void INT_DISABLE(u8 INT_index)
{
	switch (INT_index)
	{
	case INT_0:
	clear_bit(GICR,INT_0_E_BIT);//external interrupt pin 0
	break;
	case INT_1:
		clear_bit(GICR,INT_1_E_BIT);//external interrupt pin 1
		break;
	case INT_2:
		clear_bit(GICR,INT_2_E_BIT);//external interrupt pin 2
		break;
	}

}

//SET LOW LEVEL OR HIGH LEVEL OR RISING EDGE OR FALING EDGE

void INT_SET_LEVEL(u8 INT_index,u8 INT_level)//الحاله الي انا عاوزها int_level
{

	switch (INT_index)
	{
	case INT_0:
		assign_bit(MCUCR,bit_0_regester_MCUCR,get_bit(INT_level,0));//    يروح علي اول بتايه من الإندكس الي باعتهولي هات الرقم الي فيها وحطه في اول بتايه في الريجستر بغض النظر هيا 0 او 1 م
		assign_bit(MCUCR,bit_1_regester_MCUCR,get_bit(INT_level,1));//    يروح علي تاني بتايه من الإندكس الي باعتهولي هات الرقم الي فيها وحطه في تاني بتايه في الريجستر بغض النظر هيا 0 او 1م
		break;
	case INT_1:
		assign_bit(MCUCR,bit_2_regester_MCUCR,get_bit(INT_level,0));//    يروح علي اول بتايه من الإندكس الي باعتهولي هات الرقم الي فيها وحطه في تالت بتايه في الريجستر بغض النظر هيا 0 او 1م
		assign_bit(MCUCR,bit_3_regester_MCUCR,get_bit(INT_level,1));//    يروح علي تاني بتايه من الإندكس الي باعتهولي هات الرقم الي فيها وحطه في رابع بتايه في الريجستر بغض النظر هيا 0 او 1م
		break;
	case INT_2:
		assign_bit(MCUCSR,bit_6_regester_MCUCSR,INT_level);//الإنترابت دا موجود في ريجستر تاني ودي بتايه واحده غير الاتنين الي فوق ا


	}



}

//ENABLE OR DISABLE FOR ALL INTERRUPT (EXTERNAL AND INTERNAL IN MICRO EX TIMER OR ADC OR.......)
void INT_GLOBAL(u8 INT_status)
{
	assign_bit(SREG,INT_global_BIT,INT_status);//global interrupt


}





//بقول للكومبيلر متمسحش الفانكشن دي عشان محدش بيندهاها في الميين انا عارف ان محدش بيندها وعاوزها موجوده عشان الهارد وير بيندها
//اول حاجه هعمل الحاجه الي عاوز اعملها او هسنسها في الست ليفيلنج
//تاني حاجه هعمل اينيبل للانترابت الي بستخدمه
//تالت حاجه اعمل اينيبل للجلوبل
//اول م ابعت السينس واعمل الاينيبول واعمل اينيبول للجلوبل فلهارد وير لوحده لما يحدث السنس هيروح لوحده علي الفيكتور تيبول ويشوف اني عنوان انا كاتبه وانا اكيد منقص واحد عن العنوان الي الي موجود في الداتا شيت

/*void __vector_1(void)//(_1)->دي معناها ان انا كده عاوز اروح لمكان 2هو كده في الداتا شيت عشان اروح لمكان 2 في الفيكتور تيبول انقص منها 1واكتب اندراسكور الرقم الجديد
{
//frist ex
	//DIO_set_pin_value(Group_B,DIO_Pin_7,DIO_High);
//secound ex
static u8 var=0;//معاناها انها بتطول الليف تايم للفاريبول عشان الفاريابول اللوكل بيتمسح اول ما اخلص اسكوب الفانكشن ststic
			toggle_bit(var,0);
			DIO_set_pin_value(Group_B,DIO_Pin_7,var);
}*/





void __vector_1(void)
{
	pvoid_callback[0]();


}

void __vector_2(void)
{

	pvoid_callback[1]();

}


void __vector_3(void)
{
	pvoid_callback[2]();

}


set_call_back(u8 int_index,void (*ptr) (void))//بوينر هيشاور علي فانكشن مبتاخدش حاجه ومبترجعش حاجه *ptr
{
	pvoid_callback[int_index]=ptr;
}
