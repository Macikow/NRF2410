/*
 * NRF2410.c
 *
 * Created: 2015-07-18 16:37:45
 *  Author: Macikow
 */ 

/*
 * main.c
 *
 * Created: 2015-07-18 12:48:01
 *  Author: Macikow
 */ 
#define F_CPU 16000000UL
#include<avr/io.h>
#include "dbgu/dbgu.h"
#include "spi/spi.h"
#include <stdio.h>
#include <util/delay.h>
#include "dbgu/mu_termdefs.h"
#include "main.h"

#define LED_INIT (DDRB |= (1<<7))
#define LED_TOGGLE (PORTB ^= (1<<7))

static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);
static int uart_putchar(char c, FILE *stream)
{if (c == '\n')
	uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
	
}

int main(void){
	stdout = &mystdout;
	 LED_INIT;
	
	USART_init();
	printf("rozpoczêcie programu...\n");
	printf("PRR0 : %x\n",PRR0);
	nrf24_init();
	nrf24_config(1,2);
	_delay_ms(10);
	nrf24_writeSingleRegister(0x00, 0xff);
	nrf24_writeSingleRegister(0x01, 0xe5);
	//nrf24_config(1,3);
	nrf24_readSingleRegister(0x01);
	nrf24_readSingleRegister(0x00);
	
	while(1)
	{
		 LED_TOGGLE;
		
// 		spiTransmit(0x2A);
// 		spiTransmit(0x3f);
// 		spiTransmit(0x34);
// 		spiTransmit(0x56);
// 		spiTransmit(0x34);
// 		CSN_HIGH;
// 		_delay_ms(5)
// 		CSN_LOW;
// 		spiTransmit(0x2A);
// 		spiTransmit(0x3f);
// 		spiTransmit(0x34);
// 		spiTransmit(0x56);
// 		spiTransmit(0x34);
// 		CSN_HIGH;
		//LED_TOGGLE;
		//spiTransmit(0x12);
		_delay_ms(500);
	}
	return 0;
}