// Define pin numbers
const int ledPin = 13; // CHANGED
const int buttonPin = 8; // PB0

volatile bool interruptFlag = false;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Set the button pin as an input with an internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  // --- Pin Change Interrupt Setup ---
  
  // 1. Enable Pin Change Interrupt group 0 (PCIE0) for PORTB
  PCICR |= (1 << PCIE0);
  
  // 2. Enable the specific pin (PCINT0, which is Pin 8)
  PCMSK0 |= (1 << PCINT0);
  
  // 3. Enable global interrupts
  sei();
}

void loop() {
  if (interruptFlag) {
    // Toggle the LED
    digitalWrite(ledPin, !digitalRead(ledPin));
    
    // Reset the flag
    interruptFlag = false;
  }
}

// ISR for Pin Change Interrupt group 0
ISR(PCINT0_vect) {
  // Check if the pin is now LOW
  if (digitalRead(buttonPin) == LOW) {
    interruptFlag = true;
  }
}