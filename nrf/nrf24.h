/*
 * nrf24.h
 *
 * Created: 2015-07-18 16:39:12
 *  Author: Macikow
 */ 


#ifndef NRF24_H_
#define NRF24_H_
#define NRF24

#include "nRF24L01.h"
#include "../spi/spi.h"
#include <stdint.h>

#define LOW 0
#define HIGH 1

#define nrf24_ADDR_LEN 5
#define nrf24_CONFIG ((1<<EN_CRC)|(0<<CRCO))

#define NRF24_TRANSMISSON_OK 0
#define NRF24_MESSAGE_LOST   1

/* adjustment functions */
void    nrf24_init();
void    nrf24_rx_address(unsigned char* adr);
void    nrf24_tx_address(unsigned char* adr);
void    nrf24_config(unsigned char channel, unsigned char pay_length);

/* state check functions */
unsigned char nrf24_dataReady();
unsigned char nrf24_isSending();
unsigned char nrf24_getStatus();
unsigned char nrf24_rxFifoEmpty();

/* core TX / RX functions */
void    nrf24_send(unsigned char* value);
void    nrf24_getData(unsigned char* data);

/* use in dynamic length mode */
unsigned char nrf24_payloadLength();

/* post transmission analysis */
unsigned char nrf24_lastMessageStatus();
unsigned char nrf24_retransmissionCount();

/* Returns the payload length */
unsigned char nrf24_payload_length();

/* power management */
void    nrf24_powerUpRx();
void    nrf24_powerUpTx();
void    nrf24_powerDown();

/* low level interface ... */
unsigned char spi_transfer(unsigned char tx);
void    nrf24_transmitSync(unsigned char* dataout,unsigned char len);
void    nrf24_transferSync(unsigned char* dataout,unsigned char* datain,unsigned char len);
void    nrf24_configRegister(unsigned char reg, unsigned char value);
void    nrf24_readRegister(unsigned char reg, unsigned char* value, unsigned char len);
void    nrf24_writeRegister(unsigned char reg, unsigned char* value, unsigned char len);

/* -------------------------------------------------------------------------- */
/* You should implement the platform spesific functions in your code */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* In this function you should do the following things:
 *    - Set MISO pin input
 *    - Set MOSI pin output
 *    - Set SCK pin output
 *    - Set CSN pin output
 *    - Set CE pin output     */
/* -------------------------------------------------------------------------- */
void nrf24_setupPins();

/* -------------------------------------------------------------------------- */
/* nrf24 CE pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(unsigned char state);

/* -------------------------------------------------------------------------- */
/* nrf24 CE pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(unsigned char state);

/* -------------------------------------------------------------------------- */
/* nrf24 SCK pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
void nrf24_sck_digitalWrite(unsigned char state);

/* -------------------------------------------------------------------------- */
/* nrf24 MOSI pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
void nrf24_mosi_digitalWrite(unsigned char state);

/* -------------------------------------------------------------------------- */
/* nrf24 MISO pin read function
/* - returns: Non-zero if the pin is high */
/* -------------------------------------------------------------------------- */
unsigned char nrf24_miso_digitalRead();
unsigned char nrf24_readSingleRegister(unsigned char reg);
void nrf24_writeSingleRegister(unsigned char reg, unsigned char val);



#endif /* NRF24_H_ */