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
	spiInit();
	_delay_ms(250);
	
	while(1)
	{
		 LED_TOGGLE;
		
		//LED_TOGGLE;
		//spiTransmit(0x12);
		_delay_ms(500);
	}
	return 0;
}