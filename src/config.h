
#ifndef CONFIG_H_
#define CONFIG_H_

#define __AVR_ATmega328P__  // CPU Model
#define F_CPU 16000000UL    // CPU Frequency

// CPU Model define MUST be before avr/io.h
#include <avr/io.h>

#define LOW 0
#define HIGH 1
#define TRUE 1
#define FALSE 0

typedef unsigned char byte;
typedef signed char int8;           // 8 Bit    -128..127
typedef unsigned char uint8;        // 8 Bit    0..255
typedef signed short int int16;     // 16 Bit   -32768..32767
typedef unsigned short int uint16;  // 16 Bit   0..65535

#endif
