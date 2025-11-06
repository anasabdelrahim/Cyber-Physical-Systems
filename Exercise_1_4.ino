#include "sam.h" 

#define LED_PIN 10  

void setup() {
  PM->APBBMASK.reg |= PM_APBBMASK_PORT;

  PORT->Group[1].DIRSET.reg = (1 << LED_PIN);
}

void loop() {
  PORT->Group[1].OUTSET.reg = (1 << LED_PIN);
  delay(1000);

  PORT->Group[1].OUTCLR.reg = (1 << LED_PIN);
  delay(1000);
}