#include"BIT_CALC.h"
#include"STD_TYPES.h"
#include "DIO_Configuration.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

u8 DIO_set_pin_value(u8 Port_no,u8 Pin_no,u8 Pin_value){
	u8 Error_state=0;
	if(Port_no>=DIO_max_port_no){
		Error_state=1;
	}else if(Pin_no>=DIO_max_pin_no){
		Error_state=2;
	}else if((Pin_value!=DIO_Low)&&(Pin_value!=DIO_High)){
		Error_state=3;
	}else{
		switch(Port_no){
		case Group_A: assign_bit(DIO_u8_PORTA,Pin_no,Pin_value);
		break;
		case Group_B: assign_bit(DIO_u8_PORTB,Pin_no,Pin_value);
		break;
		case Group_C: assign_bit(DIO_u8_PORTC,Pin_no,Pin_value);
		break;
		case Group_D: assign_bit(DIO_u8_PORTD,Pin_no,Pin_value);
		break;
		}
	}
	return Error_state;
}

u8 DIO_set_pin_direction(u8 Port_no,u8 Pin_no,u8 Pin_direction){
	u8 Error_state=0;
		if(Port_no>=DIO_max_port_no){
			Error_state=1;
		}else if(Pin_no>=DIO_max_pin_no){
			Error_state=2;
		}else if((Pin_direction!=DIO_Input)&&(Pin_direction!=DIO_Output)){
			Error_state=3;
		}else{
			switch(Port_no){
			case Group_A: assign_bit(DIO_u8_DDRA,Pin_no,Pin_direction);
			break;
			case Group_B: assign_bit(DIO_u8_DDRB,Pin_no,Pin_direction);
			break;
			case Group_C: assign_bit(DIO_u8_DDRC,Pin_no,Pin_direction);
			break;
			case Group_D: assign_bit(DIO_u8_DDRD,Pin_no,Pin_direction);
			break;
			}
		}
		return Error_state;
}

u8 DIO_get_pin_value(u8 Port_no,u8 Pin_no,u8*Pin_value){
	u8 Error_state=0;
			if(Port_no>=DIO_max_port_no){
				Error_state=1;
			}else if(Pin_no>=DIO_max_pin_no){
				Error_state=2;
			}else{
				switch(Port_no){
				case Group_A: *Pin_value=get_bit(DIO_u8_PINA,Pin_no);
				break;
				case Group_B: *Pin_value=get_bit(DIO_u8_PINB,Pin_no);
				break;
				case Group_C: *Pin_value=get_bit(DIO_u8_PINC,Pin_no);
				break;
				case Group_D: *Pin_value=get_bit(DIO_u8_PIND,Pin_no);
				break;
				}
			}
			return Error_state;
}

u8 DIO_set_port_value(u8 Port_no,u8 Port_value){
	u8 Error_state=0;
		if(Port_no>=DIO_max_port_no){
			Error_state=1;
		}else if(Port_value>=DIO_max_port_value){
			Error_state=2;
		}else{
			switch(Port_no){
			case Group_A: DIO_u8_PORTA=Port_value;
			break;
			case Group_B: DIO_u8_PORTB=Port_value;
			break;
			case Group_C: DIO_u8_PORTC=Port_value;
			break;
			case Group_D: DIO_u8_PORTD=Port_value;
			break;
			}
		}
		return Error_state;
}

u8 DIO_set_port_direction(u8 Port_no,u8 Port_direction){
	u8 Error_state=0;
			if(Port_no>=DIO_max_port_no){
				Error_state=1;
			}else if(Port_direction>=DIO_max_port_direction){
				Error_state=2;
			}else{
				switch(Port_no){
				case Group_A: DIO_u8_DDRA=Port_direction;
				break;
				case Group_B: DIO_u8_DDRB=Port_direction;
				break;
				case Group_C: DIO_u8_DDRC=Port_direction;
				break;
				case Group_D: DIO_u8_DDRD=Port_direction;;
				break;
				}
			}
			return Error_state;
}
