#include <avr/io.h>
#include <simavr/avr/avr_mcu_section.h>

const struct avr_mmcu_vcd_trace_t traces[]  _MMCU_ = {
		{AVR_MCU_VCD_SYMBOL("PORTA"), .what = (void*) &PORTA,},
		{AVR_MCU_VCD_SYMBOL("PORTB"), .what = (void*) &PORTB,},
		{AVR_MCU_VCD_SYMBOL("PORTC"), .what = (void*) &PORTC,},
		{AVR_MCU_VCD_SYMBOL("PORTD"), .what = (void*) &PORTD,},
};

#define VOLTAGE 5000U
AVR_MCU_VOLTAGES(VOLTAGE, VOLTAGE, VOLTAGE)
