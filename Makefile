CC = avr-gcc
DEVPORT = /dev/ttyACM0
CFLAGS = -g -Wall -Wextra -O0
ATMELFLAGS = -DF_CPU=16000000UL -Os -mmcu=atmega328p

# Paths to files/libs/outputs
SRC_PATH = ./src
OUTPUT_PATH = ./bin
LIB_AVR_PATH = ./lib/avr-debugger

# Build and Link all
all: link flash

link: build_main build_lib_debug
	@echo "Link into elf/bin/hex files"
	$(CC) $(ATMELFLAGS) -o $(OUTPUT_PATH)/main.elf $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/avr8-stub.o
	avr-objcopy -O ihex -R .eeprom $(OUTPUT_PATH)/main.elf $(OUTPUT_PATH)/main.hex
	@echo "DONE"

build_main: $(SRC_PATH)/main.c
	$(CC) $(CFLAGS) $(ATMELFLAGS) -I$(LIB_AVR_PATH) -c $(SRC_PATH)/main.c -o $(OUTPUT_PATH)/main.o

build_lib_debug: $(LIB_AVR_PATH)/avr8-stub.c
	$(CC) $(CFLAGS) $(ATMELFLAGS) -I$(LIB_AVR_PATH) -c $(LIB_AVR_PATH)/avr8-stub.c -o $(OUTPUT_PATH)/avr8-stub.o

# Flash result to device memory
flash:
	@echo "Flash to device memory"
	avrdude -F -V -c arduino -p ATMEGA328P -P $(DEVPORT) -b 115200 -U flash:w:$(OUTPUT_PATH)/main.hex
	@echo "DONE"

# Clean the output dir
clean: 
	@echo "Clean bin dir"
	rm $(OUTPUT_PATH)/*
