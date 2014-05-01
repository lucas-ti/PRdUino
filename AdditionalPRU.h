#include <stdlib.h>
#include <inttypes.h>
#include "stdint.h"
#include "stdio.h"
#include <stdarg.h>
#if !defined(NULL)
    #define NULL ((void*)0)
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define true 0x1
#define false 0x0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

void ddrWrite(int address, int value);
int ddrRead(int address);

void pruDramWrite(int address, int value);
int pruDramRead(int address);

void PRU0toARMInterruptTx();
void PRU1toARMInterruptTx();
void PRU0toPRU1InterruptTx();
void PRU1toPRU0InterruptTx();

int PRU0toPRU1InterruptRx();
int PRU1toPRU0InterruptRx();
int ARMtoPRU0InterruptRx();
int ARMtoPRU1InterruptRx();
