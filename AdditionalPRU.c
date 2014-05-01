#include "AdditionalPRU.h"

void ddrWrite(int address, int value)
{
	if(address < 0x80000000 || address > 0xA0000000)
		return;
	else
	{
		uint32_t *pDdr = (uint32_t *) address;
    		pDdr[0] = value;
	}
	return;
}

int ddrRead(int address)
{
	uint32_t value;
	if(address < 0x80000000 || address > 0xA0000000)
		return -1;
	else
	{
		uint32_t *pDdr = (uint32_t *) address;
		value = pDdr[0];
	}

	return value;
}

void pruDramWrite(int address, int value)
{
	if(address > 0x00002000)
		return;
	else
	{
		uint32_t *pDdr = (uint32_t *) address;
    		pDdr[0] = value;
	}
	return;
}
int pruDramRead(int address)
{
	uint32_t value;
	if(address > 0x00002000)
		return -1;
	else
	{
		uint32_t *pDdr = (uint32_t *) address;
		value = pDdr[0];
	}
	return value;
}

void PRU0toARMInterruptTx()
{
	__R31 |= 35;
}

void PRU1toARMInterruptTx()
{
	__R31 |= 36;
}

void PRU0toPRU1InterruptTx()
{
	__R31 |= 33;
}

void PRU1toPRU0InterruptTx()
{
	__R31 |= 34;
}

int PRU0toPRU1InterruptRx()
{
	if ((__R31 |= 32) == 1)
		return 1;
	else
		return 0;
}

int PRU1toPRU0InterruptRx()
{
	if ((__R31 |= 33) == 1)
		return 1;
	else
		return 0;
}

int ARMtoPRU0InterruptRx()
{
	if ((__R31 |= 36) == 1)
		return 1;
	else
		return 0;
}

int ARMtoPRU1InterruptRx()
{
	if ((__R31 |= 37) == 1) 
		return 1;
	else
		return 0;
}
