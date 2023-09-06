#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_write_cmd(u8 cmd);
void LCD_write_data(u8 data);
void LCD_write(u8 value);
void LCD_Intialization(void);
u8 LCD_WRITE_POS(u8*data,u8 x_pos,u8 y_pos);
void reverse(u8 *arr,u8 length);
void swap (u8 *a,u8*b);
u8 LCD_WRITE_num(u32 num);//,u8 x_pos,u8 y_pos);

//study***********************************
void send_command(u8 command);

void send_data(u8 data);

void send_string(const char *string_data);
void go_pos(u8 x_pos, u8 y_pos);

void write_num (u32 num);

#endif /* LCD_INTERFACE_H_ */
