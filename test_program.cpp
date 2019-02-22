#include <avr/io.h>

int main()
{
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0x00;
	unsigned long counter = 0;

	while (true) {
		if (PIND & 0b100) {
			PORTA = ++counter;
		}
	}
}

