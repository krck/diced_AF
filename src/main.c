
#include "config.h"
#include "helper.h"

int main(void) {
    // Configure the 5th bit in the B register to be "Output" (set high)
    DDRB = setBit(DDRB, DDB5);

    while(1) {
        // LED on - Set the 5th bit in B register
        PORTB = setBit(PORTB, PORTB5);
        _delay_ms(500);

        // LED off - Clear the 5th bit in the B register
        PORTB = clearBit(PORTB, PORTB5);
        _delay_ms(500);
    }
}
