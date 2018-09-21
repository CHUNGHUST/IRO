
#include "SPI_SW.h"
#include "gpio.h"
#include "DEFINE.h"

/* Rab = 10k, Rw = 73
 * Raw = Rab*(256-data)/256 + Rw
 * Rwb = Rab*data/256 + Rw
 */
void SPISW_writeData(uint8_t channel, uint8_t datain)
{
	/* init bus */
	CS_TIN_SET;
	CS_TOUT_SET;
	CLK_RESET;
	SDO_RESET;
	/* count 16 bit : 8bit command and 8bit data */
	uint8_t cnt;
	/* 2byte temp = byte com + byte data */
	uint16_t temp;
	temp = (WRITE<<8) | datain;

	if(channel == IN_CHANNEL)  CS_TIN_RESET;
	else 	if(channel == OUT_CHANNEL) CS_TOUT_RESET;
						
	/* SPI shift 16bit */
	for(cnt = 0; cnt < 16; cnt++)
	{
		CLK_RESET;
		(temp & 0x8000) ? SDO_SET : SDO_RESET;
		CLK_SET;
		temp <<= 1;
	}
	
	CLK_RESET;
	CS_TIN_SET;
	CS_TOUT_SET;
}


