#include <stdlib.h>

#include "config.h"
#include "helper.h"
#include "avr8-stub.h"

int main(void) {
    // -------------------------------------------------------
    // Atmega328P - Arduino UNO 3
    // 4 I/O Ports (8-Bit Registers) PORT, PORTB, PORTC, PORTD
    // The LED is connected to PORT B on PIN 5
    // -------------------------------------------------------

    debug_init();

    // 2.
    // Configure the Data Direction Register (DDR) for Port B
    // (This determines if Pins on Port B are inputs or outputs - Set bit high = output)
    // DDRB = 0b00010000; // Alternative bit-syntax
    DDRB = setBit(DDRB, 5);

    // 3.
    // Start an endless loop of blinking the LED
    // (Alternate PIN 5 on PORT B between 1 and 0 with a small delay)
    int count = 0;
    char strCount[5];
    while(1) {
        breakpoint();
        PORTB = setBit(PORTB, 5);
        _delay_ms(500);

        PORTB = clearBit(PORTB, 5);
        _delay_ms(500);

        itoa(++count, strCount, 10);
        debug_message(strCount);
    }
}
