#include <avr/io.h>
#include "can.h"

int main()
{
	DDRA = 0x00;
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0x00;

	unsigned long counter = 0;
	can can{};

	while (true) {
		// uint8_t volt = can.lecture(0x0) >> 2;
		if (PIND & 0b100) {
			PORTB = ++counter;
		}
	}
}

