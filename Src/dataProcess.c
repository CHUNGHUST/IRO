
#include "dataProcess.h"
#include <stdlib.h>
#include <string.h>  // for memcpy
#include "SPI_SW.h"
#include "gpio.h"

extern uint8_t g_countPos;

void luuViTri(uint8_t *bufP, char *src)
{
	uint8_t count = 0;
	g_countPos = 0;
	
	while(*(src+count) != ']')
	{
		if(*(src+count) == '[') bufP[0] = 0;
		if(*(src+count) == ',') { g_countPos += 1; bufP[g_countPos] = count; }
		count++;
	}
	
  g_countPos += 1;
	bufP[g_countPos] = count;
	g_countPos += 1;           // so dau dem duoc khong tinh tu 0
}

static void tachChuoi(char *child, char *parent, uint8_t begin, uint8_t length)
{
	begin += 1;
	memcpy(child, (const char*)(parent+begin), length-1);
	child[length-1] = '\0';
}

static void tachPhantu(char *child, char *parent, uint8_t *bufP, uint8_t index)
{
	tachChuoi(child, parent, bufP[index-1], bufP[index] - bufP[index-1]);
}

void tachGiaTri(int16_t *bValue, char *src, uint8_t *bufP, uint8_t index)
{
	char s_bufSplit[15];
	for(uint8_t i = index; i < g_countPos; i++)
	{
		tachPhantu(s_bufSplit, src, bufP, i);
		bValue[i-index] = atoi(s_bufSplit);
	}
}

//void caiGiaTri(uint8_t channel, int16_t *bValue, uint8_t index)
//{
//	SPISW_writeData(channel, (uint8_t)(257.8688-(float)(0.0256*bValue[index])));
//}
