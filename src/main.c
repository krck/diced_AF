#include "avr_debugger.h"
#include "config.h"
#include "helper.h"

#define BAUD 115200
#define BAUDRATE ((F_CPU) / (BAUD * 16UL) - 1)  // Set baud rate value for UBRR

// Set up the UART (Universal Asynchronous Receiver/Transmitter) for serial communication
void uart_init(void) {
    UBRR0H = (BAUDRATE >> 8);                 // Shift the register right by 8 bits
    UBRR0L = BAUDRATE;                        // Set baud rate
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);    // Enable receiver and transmitter
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);  // 8bit data format
}

int main(void) {
    // -------------------------------------------------------
    // Atmega328P - Arduino UNO 3
    // 4 I/O Ports (8-Bit Registers) PORT, PORTB, PORTC, PORTD
    // The LED is connected to PORT B on PIN 5
    // -------------------------------------------------------

    uart_init();
    debug_init();

    // 1.
    // ...
    debug_init();

    // 2.
    // Configure the Data Direction Register (DDR) for Port B
    // (This determines if Pins on Port B are inputs or outputs - Set bit high = output)
    // DDRB = 0b00010000; // Alternative bit-syntax
    DDRB = setBit(DDRB, 5);

    // 3.
    // Start an endless loop of blinking the LED
    // (Alternate PIN 5 on PORT B between 1 and 0 with a small delay)
    while(1) {
        PORTB = setBit(PORTB, 5);
        _delay_ms(500);

        PORTB = clearBit(PORTB, 5);
        _delay_ms(500);
    }
}
