/*
 * spi.h
 *
 *  Created on: Jun 10, 2010
 *      Author: andi
 */

#ifndef SPI_H_
#define SPI_H_

#include <wiring.h>

typedef enum {
	CPOL_LO_CPHA_LO = 0,
	CPOL_LO_CPHA_HI = (1 << CPHA),
	CPOL_HI_CPHA_LO = (1<<CPOL),
	CPOL_HI_CPHA_HI = (1<<CPOL) | (1 << CPHA),
} ESpiMode;

class SPI
{
public:
	SPI();
	void mode( ESpiMode mode);

	byte transfer( byte value);
};

extern SPI Spi;

#endif /* SPI_H_ */
