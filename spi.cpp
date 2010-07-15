/*
 * Copyright (C) 2010 Andreas Wetzel
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <wiring.h>
#include "spi.h"

#define MISO_PIN  50
#define MOSI_PIN  51
#define SCK_PIN   52
#define SS_PIN    53

SPI::SPI()
{
	  // initialize the SPI pins
	  pinMode(SCK_PIN, OUTPUT);
	  pinMode(MOSI_PIN, OUTPUT);
	  pinMode(MISO_PIN, INPUT);
	  pinMode(SS_PIN, OUTPUT);

	  // enable SPI Master, MSB, SPI mode 0, FOSC/4
	  setup();
}


void SPI::setup( ESpiMode mode, ESpiDataOrder order, bool auto_cs)
{
	  // enable SPI master with configuration byte specified
	  SPCR = mode | order | (1<<SPE) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0);
	  _auto_cs = auto_cs;
	  setCS( false);
}

void SPI::setCS( bool setCS) {
	digitalWrite( SS_PIN, (setCS) ? LOW : HIGH);
}

byte SPI::transfer(byte value)
{
  if (_auto_cs) setCS( true);
  SPDR = value;
  while (!(SPSR & (1<<SPIF)));
  if (_auto_cs) setCS( false);
  return SPDR;
}

SPI Spi = SPI();
