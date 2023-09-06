/*
 * i2c_private.h
 *
 *  Created on: Nov 6, 2021
 *      Author: Ahmed Moataz
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWAR *((volatile u8*)0x22)
#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#define TWDR *((volatile u8*)0x23)
#define TWSR *((volatile u8*)0x21)


#endif /* I2C_PRIVATE_H_ */
