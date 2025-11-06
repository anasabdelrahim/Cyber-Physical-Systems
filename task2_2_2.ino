#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  DDRB |= (1 << DDB5);
  DDRB &= ~(1 << DDB0);
  PORTB |= (1 << PORTB0);
  PCICR |= (1 << PCIE0);
  PCMSK0 |= (1 << PCINT0);
  sei();
  while (1) {
  }
}
ISR(PCINT0_vect) {
  if (!(PINB & (1 << PINB0))) {
    PINB = (1 << PINB5);
  }
}