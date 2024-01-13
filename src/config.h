
#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__  // CPU Model
#endif
#ifndef F_CPU
#define F_CPU 16000000UL  // CPU Frequency
#endif

// CPU Model define MUST be before avr/io.h
#include <avr/io.h>
#include <util/delay.h>

#define LOW 0
#define HIGH 1
#define TRUE 1
#define FALSE 0

typedef unsigned char byte;
typedef signed char int8;     // 8 Bit    -128..127
typedef unsigned char uint8;  // 8 Bit    0..255

#endif
