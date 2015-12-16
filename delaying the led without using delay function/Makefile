CC=avr-gcc
CFLAGS=-Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
MCU=atmega328p
F_CPU=16000000UL

OBJCOPY=avr-objcopy
BIN_FORMAT=ihex

PORT=/dev/ttyUSB0
BAUD=57600
PROTOCOL=arduino
PART=m328p
AVRDUDE=avrdude -F -V

RM=rm -f

all: blink.hex
	sudo $(AVRDUDE) -c$(PROTOCOL) -p $(PART) -P $(PORT) -b $(BAUD) -D -U flash:w:$<

compile: blink.hex

blink.hex: blink.elf 
	 $(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $< $@

blink.elf: blink.o 
	 $(CC) $(CFLAGS) -o $@ $<

blink.o: blink.c 
	 $(CC) $(CFLAGS) -c -o $@ $<

upload : 
	sudo $(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) $(BAUD) -U flash:w:blink.hex

clean:
	$(RM) blink.elf blink.hex blink.s blink.out


