#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_max_port_no 4
#define DIO_max_pin_no 8

#define DIO_max_port_value 255
#define DIO_max_port_direction 255

#define DIO_High 1
#define DIO_Low 0

#define DIO_Input 0
#define DIO_Output 1

#define Group_A 0
#define Group_B 1
#define Group_C 2
#define Group_D 3

#define DIO_Pin_0 0
#define DIO_Pin_1 1
#define DIO_Pin_2 2
#define DIO_Pin_3 3
#define DIO_Pin_4 4
#define DIO_Pin_5 5
#define DIO_Pin_6 6
#define DIO_Pin_7 7
#define frist_address_in_row_two 64
#define address_counter_move_carsor_command_datasheet 0b10000000


u8 DIO_set_pin_value(u8 Port_no,u8 Pin_no,u8 Pin_value);
u8 DIO_set_pin_direction(u8 Port_no,u8 Pin_no,u8 Pin_direction);
u8 DIO_set_port_value(u8 Port_no,u8 Port_value);
u8 DIO_set_port_direction(u8 Port_no,u8 Port_direction);
u8 DIO_get_pin_value(u8 Port_no,u8 Pin_no,u8*Pin_value);
u8 DIO_get_port_value(u8 Port_no,u8*Port_value);
#endif
