/*
 * spi.c
 *
 * Created: 2015-07-18 16:38:50
 *  Author: Macikow
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "spi.h"




void spiInit(void)
{
	
	DDRSPI |= (1<<MOSI) | (1<<SCK) | (1<<SS);
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);
	CSN_HIGH;
	
	printf("init SPI SPCR : %x", SPCR);
	//printf("spi init .. \n");
}
void spiTransmit(unsigned char spiData){
	CSN_LOW;
	SPDR = spiData;
	while(!(SPSR & (1<<SPIF)));
	CSN_HIGH;
}
unsigned char spiRead(void){
	return SPDR;
}