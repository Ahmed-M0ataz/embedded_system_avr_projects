/*
 * i2c_interface.h
 *
 *  Created on: Nov 6, 2021
 *      Author: Ahmed Moataz
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_



void i2c_init_master(void);

void i2c_start(void);

void i2c_master_transmit_data(u8 data);
void i2c_master_transmit_address(u8 address);

u8 i2c_master_receive_ack(void);

u8 i2c_master_receive_not_ack(void);

void i2c_stop(void);

//***********slave***********
void i2c_init_slave(u8 slave_address);
void i2c_listen(void);
void i2c_slave_transmit_data(u8 data);
u8 i2c_master_receive_ack(void);
u8 i2c_master_receive_not_ack(void);






#endif /* I2C_INTERFACE_H_ */
