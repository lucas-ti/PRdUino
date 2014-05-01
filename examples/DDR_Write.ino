void setup()
{
}

void loop()
{
	ddrWrite(0x80000000, 0x0);
	PRU0toARMInterruptTx();	
}
