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

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(b) (1UL << (b))


//GPIO Declarations
#define GPIO0 		0x44E07000
#define GPIO1 		0x4804c000
#define GPIO2		0x481Ac000
#define GPIO3		0x481AE000
#define GPIO_DATAOUT 	0x13c

#define  SYSCFG_STANDBY_INIT		(1 << 4)

//Pins from Userspace Arduino
#define P8_03 (6u)
#define P8_04 (7u)
#define P8_05 (2u)
#define P8_06 (3u)
#define P8_07 (36u)
#define P8_08 (37u)
#define P8_09 (39u)
#define P8_10 (38u)
#define P8_11 (13u)
#define P8_12 (12u)
#define P8_13 (9u)
#define P8_14 (10u)
#define P8_15 (15u)
#define P8_16 (14u)
#define P8_17 (11u)
#define P8_18 (35u)
#define P8_19 (8u)
#define P8_20 (33u)
#define P8_21 (32u)
#define P8_22 (5u)
#define P8_23 (4u)
#define P8_24 (1u)
#define P8_25 (0u)
#define P8_26 (31u)
#define P8_27 (56u)
#define P8_28 (58u)
#define P8_29 (57u)
#define P8_30 (59u)
#define P8_31 (54u)
#define P8_32 (55u)
#define P8_33 (53u)
#define P8_34 (51u)
#define P8_35 (52u)
#define P8_36 (50u)
#define P8_37 (48u)
#define P8_38 (49u)
#define P8_39 (46u)
#define P8_40 (47u)
#define P8_41 (44u)
#define P8_42 (45u)
#define P8_43 (42u)
#define P8_44 (43u)
#define P8_45 (40u)
#define P8_46 (41u)

#define P9_11 (28u)
#define P9_12 (30u)
#define P9_13 (29u)
#define P9_14 (18u)
#define P9_15 (16u)
#define P9_16 (19u)
#define P9_17 (87u)
#define P9_18 (86u)
#define P9_19 (95u)
#define P9_20 (94u)
#define P9_21 (85u)
#define P9_22 (84u)
#define P9_23 (17u)
#define P9_24 (97u)
#define P9_25 (107u)
#define P9_26 (96u)
#define P9_27 (105u)
#define P9_28 (103u)
#define P9_29 (101u)
#define P9_30 (102u)
#define P9_31 (100u)

//Re-define
#define P9_41b (108u)
#define P9_41a (109u)
#define P9_42 (110u)
#define P9_42b (111u)
#define P8_3 (112u)
#define P8_4 (113u)
#define P8_5 (114u)
#define P8_6 (115u)
#define P8_7 (116u)
#define P8_8 (117u)
#define P8_9 (118u)

typedef unsigned int word;
typedef uint8_t boolean;
typedef uint8_t byte;

void preciseDelay1Us();
void delay1Us();
void delay1Ms();

void delay(unsigned long ms);
void delayMicroseconds(unsigned long us);

void setup(void);
void loop(void);

// Pin assignments
void init();

// To do
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);

void analogWrite(uint8_t pin, uint8_t val);

long map(long x, long in_min, long in_max, long out_min, long out_max);

void tone(uint8_t pin, uint8_t frequency);
//void tone(uint8_t pin, uint8_t frequency, uint8_t duration);
void noTone(uint8_t pin);
