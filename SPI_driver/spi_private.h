/*
 * spi_private.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Ahmed Moataz
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR *((volatile u8*)0x2D)
#define SPDR *((volatile u8*)0x2F)
#define SPSR *((volatile u8*)0x2E)

#endif /* SPI_PRIVATE_H_ */
