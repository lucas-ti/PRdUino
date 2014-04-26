#include "stdint.h"
#include "math.h"
#include "EnergiaPRU.h"
//Include here when using Energia
struct pin{
	uint32_t headerPin ;
	uint32_t gpioPin ;
	uint32_t pinOffset ;
	uint32_t gpioBank ;
};
struct pin pins[];
#include "EnergiaPRU.c"
#include "AdditionalPRU.h"
#include "AdditionalPRU.c"
void main(void)
{
	// Function call to initialize all the pins
	init();
	setup();
	for (;;)
		loop();
}

