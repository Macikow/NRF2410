/*
 * spi.c
 *
 * Created: 2015-07-18 16:38:50
 *  Author: Macikow
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "spi.h"
#include "../main.h"




void spiInit(void)
{
	DDRSPI |= (1<<MOSI) | (1<<SCK) | (1<<SS);
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);
	CSN_HIGH;
#if DEBUG
	printf("init SPI SPCR : %x\n", SPCR);
#endif
	//printf("spi init .. \n");
}
unsigned char spiTransmit(unsigned char spiData){
	SPDR = spiData;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
unsigned char spiRead(void){
	return SPDR;
}