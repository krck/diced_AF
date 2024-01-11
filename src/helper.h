
#ifndef HELPER_H_
#define HELPER_H_

// Manipulation (write bit to register)
#define setBit(reg, bit) (reg | (1 << bit))     // Set a Bit in an Register to 1
#define clearBit(reg, bit) (reg & ~(1 << bit))  // Set a Bit in an Register to 0
#define toggleBit(reg, bit) (reg ^ (1 << bit))  // Negate a Bit in an Register
// Selection (read bit from register)
#define isSet(reg, bit) (reg & (1 << bit))       // Check if a Bit in an Register is 1
#define isClear(reg, bit) (!(reg & (1 << bit)))  // Check if a Bin in an Register is 0

#endif
