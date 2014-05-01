int x;

void setup()
{
}

void loop()
{
	x= pruDramRead(0x0);
	pruDramWrite(0x4, x);
	PRU0toARMInterruptTx();	
}
