int bitTest = 0; 
int bitSetTest; 
int bitClearTest; 
int bitWriteTest; 
int bitReadTest; 
int temp;
word lowByteTest; 
word highByteTest;

void setup() 
{ 
} 

void loop() 
{ 
	// Writing the low byte of 0x5678 to memory
	lowByteTest = lowByte(0x5678); 
	ddrWrite(0x80000000, lowByteTest); 

	// Writing the high byte of 0x5678 to memory
	highByteTest = highByte(0x5678); 
	ddrWrite(0x80000004, highByteTest); 

	// Determines value of 0x1 and writes to memory
	bitTest = bit(0x1); 
	ddrWrite(0x80000008, bitTest); 

	// Writes a 1 to the 0th bit of bitWriteTest
	bitWriteTest = 0x4; 
	bitWrite(bitWriteTest, 0, 1); 
	ddrWrite(0x8000000C, bitWriteTest); 

	// Writes a zero to the 0th bit of bitWrite Test
	bitWriteTest = 0x5; 
	bitWrite(bitWriteTest, 0, 0); 
	ddrWrite(0x80000010, bitWriteTest); 

	// Sets the 1st bit of bitSetTest
	bitSetTest = 0x5; 
	bitSet(bitSetTest, 1); 
	ddrWrite(0x80000014, bitSetTest);

	// Clears the 2nd bit of bitClearTest
	bitClearTest = 0x5; 
	bitClear(bitClearTest, 2); 
	ddrWrite(0x80000018, bitClearTest);  	

	// Clears the first bit of bitReadTest
	bitReadTest = 0x5; 
	bitClearTest = bitRead(bitClearTest, 1); 
	ddrWrite(0x8000001C, bitClearTest); 

	// Writes the minimum of 5 and 10 to memory
	temp = min(5,10); 
	ddrWrite(0x80000020, temp); 

	// Writes the maximum of 5 and 10 to memory
	temp = max(5,10); 
	ddrWrite(0x80000024, temp); 

	PRU0toARMInterruptTx(); 
}
