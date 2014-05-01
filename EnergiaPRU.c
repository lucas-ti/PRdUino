#include "EnergiaPRU.h"

volatile register unsigned int __R30; 
volatile register unsigned int __R31;

void preciseDelay1Us()
{
	asm (" LDI r0, 92");
	asm ("DELAY:");
	asm (" SUB r0, r0, 1");
	asm (" QBNE DELAY, r0, 0");
}

void delay1Us()
{
	volatile unsigned long i;
	for(i = 0; i < 17; i++);
}

void delay1Ms()
{
	volatile unsigned long i;
	for(i = 0; i < 18280; i++);
}

void delay(unsigned long ms)
{
	volatile unsigned long i;

	for(i = 0; i < ms; i++)
	{
		delay1Ms();
	};
	return;
}

void delayMicroseconds(unsigned long us)
{
	volatile unsigned long i;
	for(i = 0; i < us; i++)
	{
		preciseDelay1Us();
	};	
	return;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	if (pin < 28)
	{
		if (val == HIGH)
			__R30 |= pins[pin].pinOffset;
		else
			__R30 &= ~pins[pin].pinOffset;
	}
	else
	{
		uint32_t *pgpio = (uint32_t *) (pins[pin].gpioBank | GPIO_DATAOUT);
		if (val == HIGH)
			*pgpio |= pins[pin].pinOffset;
		else
			*pgpio &= ~pins[pin].pinOffset;
	}
	return;
}

// Supports only PRU eGPI
int digitalRead(uint8_t pin)
{
	int value = -1;
	if ((__R31 & pins[pin].pinOffset) == 1)
	{
		value = HIGH;
	}
	else if ((__R31 & pins[pin].pinOffset) == 0)
	{
		value = LOW;
	}
	return value;
}

// http://arduino.cc/en/Reference/Map#.Ux_xLqp385Y
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void init()
{
	// Turn off OCP port
	uint32_t *pPrcm = (uint32_t *) 0x00026004;
	pPrcm[0] &= ~SYSCFG_STANDBY_INIT;

	pins[0].headerPin = P8_15; //R31
	pins[0].gpioPin = 47;
	pins[0].pinOffset = (1<<15);
	pins[1].headerPin = P8_16; //R31
	pins[1].gpioPin = 48;
	pins[1].pinOffset = (1<<14);
	pins[2].headerPin = P8_11;
	pins[2].gpioPin = 45;
	pins[2].pinOffset = (1<<15);
	pins[3].headerPin = P8_12;
	pins[3].gpioPin = 44;
	pins[3].pinOffset = (1<<14);
	pins[4].headerPin = P8_20;
	pins[4].gpioPin = 63;
	pins[4].pinOffset = (1<<13);
	pins[5].headerPin = P8_21;
	pins[5].gpioPin = 62;
	pins[5].pinOffset = (1<<12);
	pins[6].headerPin = P8_28;
	pins[6].gpioPin = 88;
	pins[6].pinOffset = (1<<10);
	pins[7].headerPin = P8_29;
	pins[7].gpioPin = 87;
	pins[7].pinOffset = (1<<9);
	pins[8].headerPin = P8_27;
	pins[8].gpioPin = 86;
	pins[8].pinOffset = (1<<8);
	pins[9].headerPin = P8_40;
	pins[9].gpioPin = 77;
	pins[9].pinOffset = (1<<7);
	pins[10].headerPin = P8_39;
	pins[10].gpioPin = 76;
	pins[10].pinOffset = (1<<6);
	pins[11].headerPin = P8_42;
	pins[11].gpioPin = 75;
	pins[11].pinOffset = (1<<5);
	pins[12].headerPin = P8_41;
	pins[12].gpioPin = 74;
	pins[12].pinOffset = (1<<4);
	pins[13].headerPin = P8_44;
	pins[13].gpioPin = 73;
	pins[13].pinOffset = (1<<3);
	pins[14].headerPin = P8_43;
	pins[14].gpioPin = 72;
	pins[14].pinOffset = (1<<2);
	pins[15].headerPin = P8_46;
	pins[15].gpioPin = 71;
	pins[15].pinOffset = (1<<1);
	pins[16].headerPin = P8_45;
	pins[16].gpioPin = 70;
	pins[16].pinOffset = (1<<0);

	pins[17].headerPin = P9_26;
	pins[17].gpioPin = 14;
	pins[17].pinOffset = (1<<16);
	pins[18].headerPin = P9_24;
	pins[18].gpioPin = 15;
	pins[18].pinOffset = (1<<16);
	pins[19].headerPin = P9_41b;
	pins[19].gpioPin = 20;
	pins[19].pinOffset = (1<<16);

	pins[20].headerPin = P9_25;
	pins[20].gpioPin = 117;
	pins[20].pinOffset = (1<<7);
	pins[21].headerPin = P9_41a;
	pins[21].gpioPin = 116;
	pins[21].pinOffset = (1<<6);
	pins[22].headerPin = P9_27;
	pins[22].gpioPin = 115;
	pins[22].pinOffset = (1<<5);
	pins[23].headerPin = P9_42;
	pins[23].gpioPin = 114;
	pins[23].pinOffset = (1<<4);
	pins[24].headerPin = P9_28;
	pins[24].gpioPin = 113;
	pins[24].pinOffset = (1<<3);
	pins[25].headerPin = P9_30;
	pins[25].gpioPin = 112;
	pins[25].pinOffset = (1<<2);
	pins[26].headerPin = P9_29;
	pins[26].gpioPin = 111;
	pins[26].pinOffset = (1<<1);
	pins[27].headerPin = P9_31;
	pins[27].gpioPin = 110;
	pins[27].pinOffset = (1<<0);

//Starting of non-PRU GPIO
	pins[28].headerPin = P8_3;
	pins[28].gpioPin = 38;
	pins[28].pinOffset = (1<<6);
	pins[28].gpioBank = GPIO1;
	pins[29].headerPin = P8_4;
	pins[29].gpioPin = 39;
	pins[29].pinOffset = (1<<7);
	pins[29].gpioBank = GPIO1;
	pins[30].headerPin = P8_5;
	pins[30].gpioPin = 34;
	pins[30].pinOffset = (1<<2);
	pins[30].gpioBank = GPIO1;
	pins[31].headerPin = P8_6;
	pins[31].gpioPin = 35;
	pins[31].pinOffset = (1<<3);
	pins[31].gpioBank = GPIO1;
	pins[32].headerPin = P8_7;
	pins[32].gpioPin = 66;
	pins[32].pinOffset = (1<<2);
	pins[32].gpioBank = GPIO2;
	pins[33].headerPin = P8_8;
	pins[33].gpioPin = 67;
	pins[33].pinOffset = (1<<3);
	pins[33].gpioBank = GPIO2;
	pins[34].headerPin = P8_9;
	pins[34].gpioPin = 69;
	pins[34].pinOffset = (1<<5);
	pins[34].gpioBank = GPIO2;
	pins[35].headerPin = P8_10;
	pins[35].gpioPin = 68;
	pins[35].pinOffset = (1<<4);
	pins[35].gpioBank = GPIO2;
	pins[36].headerPin = P8_13;
	pins[36].gpioPin = 23;
	pins[36].pinOffset = (1<<23);
	pins[36].gpioBank = GPIO0;
	pins[37].headerPin = P8_14;
	pins[37].gpioPin = 26;
	pins[37].pinOffset = (1<<26);
	pins[37].gpioBank = GPIO0;
	pins[38].headerPin = P8_17;
	pins[38].gpioPin = 27;
	pins[38].pinOffset = (1<<27);
	pins[38].gpioBank = GPIO0;
	pins[39].headerPin = P8_19;
	pins[39].gpioPin = 22;
	pins[39].pinOffset = (1<<22);
	pins[39].gpioBank = GPIO0;
	pins[40].headerPin = P8_22;
	pins[40].gpioPin = 37;
	pins[40].pinOffset = (1<<5);
	pins[40].gpioBank = GPIO1;
	pins[41].headerPin = P8_23;
	pins[41].gpioPin = 36;
	pins[41].pinOffset = (1<<4);
	pins[41].gpioBank = GPIO1;
	pins[42].headerPin = P8_24;
	pins[42].gpioPin = 33;
	pins[42].pinOffset = (1<<1);
	pins[42].gpioBank = GPIO1;
	pins[43].headerPin = P8_25;
	pins[43].gpioPin = 32;
	pins[43].pinOffset = (1<<0);
	pins[43].gpioBank = GPIO1;
	pins[44].headerPin = P8_26;
	pins[44].gpioPin = 61;
	pins[44].pinOffset = (1<<29);
	pins[44].gpioBank = GPIO1;
	pins[45].headerPin = P8_30;
	pins[45].gpioPin = 89;
	pins[45].pinOffset = (1<<25);
	pins[45].gpioBank = GPIO2;
	pins[46].headerPin = P9_17;
	pins[46].gpioPin = 5;
	pins[46].pinOffset = (1<<5);
	pins[46].gpioBank = GPIO0;
	pins[47].headerPin = P9_18;
	pins[47].gpioPin = 4;
	pins[47].pinOffset = (1<<4);
	pins[47].gpioBank = GPIO0;
	pins[48].headerPin = P9_19;
	pins[48].gpioPin = 13;
	pins[48].pinOffset = (1<<13);
	pins[48].gpioBank = GPIO0;
	pins[49].headerPin = P9_20;
	pins[49].gpioPin = 12;
	pins[49].pinOffset = (1<<12);
	pins[49].gpioBank = GPIO0;
	pins[50].headerPin = P8_18;
	pins[50].gpioPin = 65;
	pins[50].pinOffset = (1<<1);
	pins[50].gpioBank = GPIO2;
	pins[51].headerPin = P8_31;
	pins[51].gpioPin = 10;
	pins[51].pinOffset = (1<<10);
	pins[51].gpioBank = GPIO0;
	pins[52].headerPin = P8_32;
	pins[52].gpioPin = 11;
	pins[52].pinOffset = (1<<11);
	pins[52].gpioBank = GPIO0;
	pins[53].headerPin = P8_33;
	pins[53].gpioPin = 9;
	pins[53].pinOffset = (1<<9);
	pins[53].gpioBank = GPIO0;
	pins[54].headerPin = P8_34;
	pins[54].gpioPin = 81;
	pins[54].pinOffset = (1<<17);
	pins[54].gpioBank = GPIO2;
	pins[55].headerPin = P8_35;
	pins[55].gpioPin = 8;
	pins[55].pinOffset = (1<<8);
	pins[55].gpioBank = GPIO0;
	pins[56].headerPin = P8_36;
	pins[56].gpioPin = 80;
	pins[56].pinOffset = (1<<16);
	pins[56].gpioBank = GPIO2;
	pins[57].headerPin = P8_37;
	pins[57].gpioPin = 78;
	pins[57].pinOffset = (1<<14);
	pins[57].gpioBank = GPIO2;
	pins[58].headerPin = P8_38;
	pins[58].gpioPin = 79;
	pins[58].pinOffset = (1<<15);
	pins[58].gpioBank = GPIO2;
	pins[59].headerPin = P9_11;
	pins[59].gpioPin = 30;
	pins[59].pinOffset = (1<<30);
	pins[59].gpioBank = GPIO0;
	pins[60].headerPin = P9_12;
	pins[60].gpioPin = 60;
	pins[60].pinOffset = (1<<28);
	pins[60].gpioBank = GPIO1;
	pins[61].headerPin = P9_13;
	pins[61].gpioPin = 31;
	pins[61].pinOffset = (1<<31);
	pins[61].gpioBank = GPIO0;
	pins[62].headerPin = P9_14;
	pins[62].gpioPin = 50;
	pins[62].pinOffset = (1<<18);
	pins[62].gpioBank = GPIO1;
	pins[63].headerPin = P9_15;
	pins[63].gpioPin = 48;
	pins[63].pinOffset = (1<<16);
	pins[63].gpioBank = GPIO1;
	pins[64].headerPin = P9_16;
	pins[64].gpioPin = 51;
	pins[64].pinOffset = (1<<19);
	pins[64].gpioBank = GPIO1;
	pins[65].headerPin = P9_21;
	pins[65].gpioPin = 3;
	pins[65].pinOffset = (1<<3);
	pins[65].gpioBank = GPIO0;
	pins[66].headerPin = P9_22;
	pins[66].gpioPin = 2;
	pins[66].pinOffset = (1<<2);
	pins[66].gpioBank = GPIO0;
	pins[67].headerPin = P9_23;
	pins[67].gpioPin = 49;
	pins[67].pinOffset = (1<<17);
	pins[67].gpioBank = GPIO1;
	pins[68].headerPin = P9_41a;
	pins[68].gpioPin = 20;
	pins[68].pinOffset = (1<<20);
	pins[68].gpioBank = GPIO0;
	pins[69].headerPin = P9_42b;
	pins[69].gpioPin = 7;
	pins[69].pinOffset = (1<<7);
	pins[69].gpioBank = GPIO0;

	pins[70].headerPin = P8_15;
	pins[70].gpioPin = 47;
	pins[70].pinOffset = (1<<15);
	pins[70].gpioBank = GPIO1;
	pins[71].headerPin = P8_16;
	pins[71].gpioPin = 46;
	pins[71].pinOffset = (1<<14);
	pins[71].gpioBank = GPIO1;
	pins[72].headerPin = P8_11;
	pins[72].gpioPin = 45;
	pins[72].pinOffset = (1<<13);
	pins[72].gpioBank = GPIO1;
	pins[73].headerPin = P8_12;
	pins[73].gpioPin = 44;
	pins[73].pinOffset = (1<<12);
	pins[73].gpioBank = GPIO1;

	


	return;
}
