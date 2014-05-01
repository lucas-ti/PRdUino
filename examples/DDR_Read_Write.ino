int x;

void setup()
{
}

void loop()
{
	x= ddrRead(0x80000000);
	ddrWrite(0x80000004, x);
	PRU0toARMInterruptTx();	
}
