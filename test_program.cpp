#include <avr/io.h>

int main()
{
	DDRA = 0x00;
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;
	unsigned long counter = 0;

	while (true) {
		if (PINA & 0x1) {
			PORTD = ++counter;
		}
	}
}

