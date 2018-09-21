
#ifndef _SPI_SW_H_
#define _SPI_SW_H_

#include "stm32f1xx_hal.h"
#include "gpio.h"



/*
 * @brief: send data to MCP41010
 * @param: num: id MCP41010 
 * @retval: datain: data to store in MCP41010
 */

void SPISW_writeData(uint8_t channel, uint8_t datain);

#endif
