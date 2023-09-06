/*
 * DIO_PRORAM.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Ahmed Moataz
 */
//imblimentation fanction
#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

//FUNCTION FOR OUTPUT (REG PORT) FOR 1 PIN **************
u8 DIO_SET_PIN_VALUE(u8 PORT_NB,u8 PIN_NB,u8 PIN_VALUE)//RIGESTER PORT PIN PIN....
{u8 ERROR_STATE=0;
	if (PORT_NB>=DIO_MAX_PORT_NB)
	{
		ERROR_STATE=1;//PORT ERROR

	}else if (PIN_NB >= DIO_MAX_PIN_NB)

	{
		ERROR_STATE=2;//PIN ERROR

	}else if((PIN_VALUE !=DIO_LOW)&&(PIN_VALUE!=DIO_HIGH))
	{

		ERROR_STATE=3;//VALUE ERROR
	}
	else
	{

		switch (PORT_NB)
		{
		case GROUP_A:
					assign_bit(DIO_U8_PORTA,PIN_NB,PIN_VALUE);
			break;
		case GROUP_B:
					assign_bit(DIO_U8_PORTB,PIN_NB,PIN_VALUE);
			break;
		case GROUP_C:
					assign_bit(DIO_U8_PORTC,PIN_NB,PIN_VALUE);
			break;
		case GROUP_D:
					assign_bit(DIO_U8_PORTD,PIN_NB,PIN_VALUE);
			break;
		}


	}



return ERROR_STATE;
}

//FUNCTION FOR DIRECTION (REG DDR) FOR 1 PIN **************


u8 DIO_SET_PIN_DIRECTION(u8 PORT_NB,u8 PIN_NB,u8 PIN_DIRECTION)//RIGESTER PORT PIN PIN....
{u8 ERROR_STATE=0;
	if (PORT_NB>=DIO_MAX_PORT_NB)
	{
		ERROR_STATE=1;//PORT ERROR

	}else if (PIN_NB >= DIO_MAX_PIN_NB)

	{
		ERROR_STATE=2;//PIN ERROR

	}else if((PIN_DIRECTION !=DIO_INPUT)&&(PIN_DIRECTION!=DIO_OUTPUT))
	{

		ERROR_STATE=3;//VALUE ERROR
	}
	else
	{

		switch (PORT_NB)
		{
		case GROUP_A:
					assign_bit(DIO_U8_DDRA,PIN_NB,PIN_DIRECTION);
			break;
		case GROUP_B:
					assign_bit(DIO_U8_DDRB,PIN_NB,PIN_DIRECTION);
			break;
		case GROUP_C:
					assign_bit(DIO_U8_DDRC,PIN_NB,PIN_DIRECTION);
			break;
		case GROUP_D:
					assign_bit(DIO_U8_DDRD,PIN_NB,PIN_DIRECTION);
			break;
		}


	}



return ERROR_STATE;
}

//FUNCTION FOR GET VALUE (REG PIN) FOR 1 PIN **************


u8 DIO_GET_PIN_VALUE(u8 PORT_NB,u8 PIN_NB,u8 *PIN_VALUE)//RIGESTER PORT PIN PIN....
{u8 ERROR_STATE=0;
	if (PORT_NB>=DIO_MAX_PORT_NB)
	{
		ERROR_STATE=1;//PORT ERROR

	}else if (PIN_NB >= DIO_MAX_PIN_NB)

	{
		ERROR_STATE=2;//PIN ERROR

	}
	else
	{

		switch (PORT_NB)
		{
		case GROUP_A:
			*PIN_VALUE = get_bit(DIO_U8_PINA,PIN_NB);
			break;
		case GROUP_B:
			*PIN_VALUE = get_bit(DIO_U8_PINB,PIN_NB);
			break;
		case GROUP_C:
			*PIN_VALUE = get_bit(DIO_U8_PINC,PIN_NB);
			break;
		case GROUP_D:
			*PIN_VALUE = get_bit(DIO_U8_PIND,PIN_NB);
			break;
		}


	}



return ERROR_STATE;
}


//FUNCTION FOR OUTPUT VALUE (REG PORT) FOR 8 PIN **************


u8 DIO_SET_PORT_VALUE(u8 PORT_NB,u8 PORT_VALUE)//RIGESTER PORT (PORT PORT....
{u8 ERROR_STATE=0;
	if (PORT_NB>=DIO_MAX_PORT_NB)
	{
		ERROR_STATE=1;//PORT ERROR

	}else if (PORT_VALUE > DIO_MAX_PORT_VALUE)

	{
		ERROR_STATE=2;//(port (pins) value) ERROR

	}
	else
	{

		switch (PORT_NB)
		{
		case GROUP_A:
			DIO_U8_PORTA=PORT_VALUE;
			break;
		case GROUP_B:
			DIO_U8_PORTB=PORT_VALUE;
			break;
		case GROUP_C:
			DIO_U8_PORTC=PORT_VALUE;
			break;
		case GROUP_D:
			DIO_U8_PORTD=PORT_VALUE;
			break;
		}


	}



return ERROR_STATE;
}


//FUNCTION FOR DIRECTION (REG DDR) FOR 8 PIN **************


u8 DIO_SET_PORT_DIRECTION(u8 PORT_NB,u8 PORT_DIRECTION)//RIGESTER PORT (PORT PORT....
{u8 ERROR_STATE=0;
	if (PORT_NB>=DIO_MAX_PORT_NB)
	{
		ERROR_STATE=1;//PORT ERROR

	}else if (PORT_DIRECTION > DIO_MAX_PORT_DIRECTION)

	{
		ERROR_STATE=2;//(port (8pins) value) ERROR

	}
	else
	{

		switch (PORT_NB)
		{
		case GROUP_A:
			DIO_U8_DDRA=PORT_DIRECTION;
			break;
		case GROUP_B:
			DIO_U8_DDRB=PORT_DIRECTION;
			break;
		case GROUP_C:
			DIO_U8_DDRC=PORT_DIRECTION;
			break;
		case GROUP_D:
			DIO_U8_DDRD=PORT_DIRECTION;
			break;
		}


	}



return ERROR_STATE;
}



