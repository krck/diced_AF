# diced_AF (Atmel Firmware)

## About
Using a Arduino UNO 3
- For now: Arduino Playground
- Future plan: Handheld Dice-Roller Device

## Setup (Linux)
Development is done "bare bones, but with some reasonable comfort", to keep the toolchain simple and avoid bloated installations. No full Arduino IDE. No Atmel Studio. The core setup is just VS Code with the following extensions:
- C/C++
- PlatformIO (needed for debugging)

These packages/libs are needed for manually compiling/flashing (without PlatformIO). Also add the "avr" library as a header include path in VS Code (prob.: `/usr/lib/avr`):
- binutils
- gcc-avr
- gdb-avr
- avr-libc
- avrdude

## Compile
These steps are needed for manually compiling the program and flashing it onto the Arduino Uno. First compile the C code into a Hex file. Commands are prefilled for the Arduino UNO 3 (Atmega328p / 16000000UL):

```
> avr-gcc -g -DF_CPU=16000000UL -Os -mmcu=atmega328p -c src/main.c -o bin/main.o
> avr-gcc -g -mmcu=atmega328p -o bin/main.bin bin/main.o
> avr-objcopy -O ihex -R .eeprom bin/main.bin bin/main.hex
```

Finally flash the hex file to the on-chip memory of the Atmega with the help of avrdude (but find the connected USB device first):

```
> ls /dev/ | grep ACM
> avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:bin/main.hex
```