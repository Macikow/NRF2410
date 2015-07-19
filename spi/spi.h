/*
 * spi.h
 *
 * Created: 2015-07-18 16:39:36
 *  Author: Macikow
 */ 


#ifndef SPI_H_
#define SPI_H_

#define DDRSPI DDRB
#define SPI_PORT PORTB
#define MOSI 2
#define MISO 3
#define SS 0
#define SCK 1

#define CSN_HIGH (SPI_PORT|= (1<<SS))
#define CSN_LOW (SPI_PORT &= ~(1<<SS))

void spiIinit(void);
void spiTransmit(unsigned char spiData);
unsigned char spiRead(void);

#endif /* SPI_H_ */