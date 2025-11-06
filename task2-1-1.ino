#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  
  DDRB |= (1 << DDB5);
  DDRD &= ~(1 << DDD2);
  PORTD |= (1 << PORTD2);
  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);
  EIMSK |= (1 << INT0);
  
  sei();

  while (1) {
  }
}
ISR(INT0_vect) {
  PINB = (1 << PINB5); // CHANGED
}