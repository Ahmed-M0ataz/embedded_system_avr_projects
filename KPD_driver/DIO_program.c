/*
 * DIO_program.c
 *
 *  Created on: Sep 10, 2021
 *      Author: user
 */
#include "BIT_CALC.h"
#include "std_types.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

U8 DIO_set_pin_direction(U8 port_NB,U8 pin_NB,U8 pin_direction)
{
U8 error_state = 0;
if(port_NB>= DIO_Max_port_NB)
{
	error_state = 1;
}
else if(pin_NB>=DIO_Max_pin_NB )
{
	error_state = 1;
}
else if((pin_direction !=DIO_Input) && (pin_direction!=DIO_Output))
{
	error_state = 1;
}
else{
     switch(port_NB){
      case Group_A:
	   assign_bit(DIO_U8_DDRA,pin_NB,pin_direction);
	   break;
	   case Group_B:
	   assign_bit(DIO_U8_DDRB,pin_NB,pin_direction);
	   break;
     case Group_C:
	   assign_bit(DIO_U8_DDRC,pin_NB,pin_direction);
	   break;
     case Group_D:
	   assign_bit(DIO_U8_DDRD,pin_NB,pin_direction);
	   break;
}
}

return error_state;
}


U8 DIO_set_pin_value(U8 port_NB,U8 pin_NB,U8 pin_value)
{
U8 error_state = 0;
if(port_NB>= DIO_Max_port_NB)
{
	error_state = 1;
}
else if(pin_NB>=DIO_Max_pin_NB)
{
	error_state = 1;
}
else if((pin_value!=DIO_High) && (pin_value!=DIO_Low))
{
	error_state = 1;
}
else{
     switch(port_NB){
      case Group_A:
	   assign_bit(DIO_U8_PORTA,pin_NB,pin_value);
	   break;
	   case Group_B:
	   assign_bit(DIO_U8_PORTB,pin_NB,pin_value);
	   break;
     case Group_C:
	   assign_bit(DIO_U8_PORTC,pin_NB,pin_value);
	   break;
     case Group_D:
	   assign_bit(DIO_U8_PORTD,pin_NB,pin_value);
	   break;
     }
}


return error_state;
}


U8 DIO_set_port_value(U8 port_NB,U8 port_value)
{
U8 error_state = 0;
if(port_NB>= DIO_Max_port_NB)
{
	error_state = 1;
}

else if(port_value>DIO_Max_port_value)
{
	error_state = 1;
}
else{
     switch(port_NB){
      case Group_A:
    	  DIO_U8_PORTA = port_value;
	   break;
	   case Group_B:
		   DIO_U8_PORTB = port_value;
	   break;
     case Group_C:
    	 DIO_U8_PORTC = port_value;
	   break;
     case Group_D:
    	 DIO_U8_PORTD = port_value;
	   break;
     }
}


return error_state;
}


U8 DIO_set_port_direction(U8 port_NB, U8 port_direction)
{
U8 error_state = 0;
if(port_NB>= DIO_Max_port_NB)
{
	error_state = 1;
}

else if( port_direction>DIO_Max_port_direction )
{
	error_state = 1;
}
else{
     switch(port_NB){
      case Group_A:
    	  DIO_U8_DDRA = port_direction;
	   break;
	   case Group_B:
		   DIO_U8_DDRB = port_direction;
	   break;
     case Group_C:
    	 DIO_U8_DDRC = port_direction;
	   break;
     case Group_D:
    	 DIO_U8_DDRD = port_direction;
	   break;
     }
}


return error_state;
}



U8 DIO_get_pin_value(U8 port_NB,U8  pin_NB,U8 * pin_value)
{
U8 error_state = 0;
if(port_NB>= DIO_Max_port_NB)
{
	error_state = 1;
}
else if(pin_NB>=DIO_Max_pin_NB)
{
	error_state = 1;
}

else{
     switch(port_NB){
      case Group_A:
    	  * pin_value = get_bit(DIO_U8_PINA,pin_NB);
	   break;
	   case Group_B:
		   * pin_value=get_bit(DIO_U8_PINB,pin_NB);
	   break;
     case Group_C:
    	 * pin_value=get_bit(DIO_U8_PINC,pin_NB);
	   break;
     case Group_D:
    	 * pin_value=get_bit(DIO_U8_PIND,pin_NB);
	   break;
     }

}
return error_state;
}







