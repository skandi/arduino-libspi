/*
 * spi.cpp
 *
 *  Created on: Jun 10, 2010
 *      Author: andi
 */

#include <wiring.h>
#include "spi.h"

#define MISO_PIN  50
#define MOSI_PIN  51
#define SCK_PIN   52
#define SS_PIN    53

SPI::SPI() {
	  // initialize the SPI pins
	  pinMode(SCK_PIN, OUTPUT);
	  pinMode(MOSI_PIN, OUTPUT);
	  pinMode(MISO_PIN, INPUT);
	  pinMode(SS_PIN, OUTPUT);

	  // enable SPI Master, MSB, SPI mode 0, FOSC/4
	  mode( CPOL_LO_CPHA_LO);
}


void SPI::mode( ESpiMode mode) {
	  // enable SPI master with configuration byte specified
	  SPCR = 0;
	  SPCR = (mode & 0x7F) | (1<<SPE) | (1<<MSTR)| (1<<SPR1) | (1<<SPR0);
}

byte SPI::transfer(byte value)
{
  digitalWrite( SS_PIN, LOW);
  SPDR = value;
  while (!(SPSR & (1<<SPIF))) ;
  digitalWrite( SS_PIN, HIGH);
  return SPDR;
}

SPI Spi = SPI();
