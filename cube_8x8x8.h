#ifndef MAIN_H
#define MAIN_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "cube.h"

#define DATA_BUS PORTB
#define LAYER_SELECT PORTC
#define LATCH_PIN PORTB2
#define OE PORTB0

typedef unsigned char byte;

void ioinit (void);
void bootmsg (void);
void sendSPI (uint8_t _data);
void rs232(void);
void dolayer(unsigned char layer);

// #define USART_BAUDRATE 38400
// #define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
// #define BAUD_PRESCALE F_CPU/16/USART_BAUDRATE-1

#define FOSC 16000000
#define BAUD 115200
#define MYUBRR FOSC/16/BAUD-1
void USART_Init( unsigned int ubrr);

volatile unsigned char current_layer;
volatile unsigned char pgm_mode;
unsigned int bootwait (void);
#endif

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR

const byte layerfix[8] = {4, 1, 2, 6, 5, 0, 3, 7}; // doing it in order gave me 5,1,2,6,0,4,3,7
const int effectsList[20] = {5,6,7,8,9,7,14,19,16,18,7,0,8,23,24};
