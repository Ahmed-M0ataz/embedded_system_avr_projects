/*
 * spi_interface.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Ahmed Moataz
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



void spi_init_master(void);


void spi_init_slave(void);

u8 spi_transfer(u8 data);



#endif /* SPI_INTERFACE_H_ */
