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

#ifndef SPI_H_
#define SPI_H_

#include <wiring.h>

typedef enum {
	MSB_FIRST = 0,
	LSB_FIRST = (1<<DORD),
} ESpiDataOrder;

typedef enum {
	CPOL_LO_CPHA_LO = 0,
	CPOL_LO_CPHA_HI = (1<<CPHA),
	CPOL_HI_CPHA_LO = (1<<CPOL),
	CPOL_HI_CPHA_HI = (1<<CPOL) | (1<<CPHA),
} ESpiMode;

class SPI
{
public:
	SPI();
	void setup( ESpiMode mode=CPOL_LO_CPHA_LO, ESpiDataOrder order=MSB_FIRST, bool auto_cs=true);

	void setCS( bool setcs);

	byte transfer( byte value=0xff);

private:
	bool _auto_cs;
};

extern SPI Spi;

#endif /* SPI_H_ */
