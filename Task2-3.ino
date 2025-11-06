#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  DDRB |= (1 << DDB5);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  OCR1A = 15625;
  TIMSK1 |= (1 << OCIE1A);
  sei();
  while (1) {
  }
}
ISR(TIMER1_COMPA_vect) {
  PINB = (1 << PINB5);
}