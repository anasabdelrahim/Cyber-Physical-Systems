float num1, num2, result;
char op;
String input;

enum State { WAIT_NUM1, WAIT_OP, WAIT_NUM2 };
State currentState = WAIT_NUM1;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Enter first number:");
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() == 0) 
    {
      return;
    }

    switch (currentState) {
      case WAIT_NUM1:
        num1 = input.toFloat();
        Serial.println(num1);
        Serial.println("Enter operation (+, -, *, /):");
        currentState = WAIT_OP;
        break;

      case WAIT_OP:
        op = input.charAt(0);
        Serial.println(op);
        if (op != '+' && op != '-' && op != '*' && op != '/') {
          Serial.println("Invalid operator. Please enter one of +, -, *, /:");
          break;
        }
        Serial.println("Enter second number:");
        currentState = WAIT_NUM2;
        break;

      case WAIT_NUM2:
        num2 = input.toFloat();
        Serial.println(num2);

        switch (op) {
          case '+':
            result = num1 + num2;
            break;
          case '-':
            result = num1 - num2;
            break;
          case '*':
            result = num1 * num2;
            break;
          case '/':
            if (num2 == 0) {
              Serial.println("Error: Division by zero");
              Serial.println("Enter first number:");
              currentState = WAIT_NUM1;
              return;
            }
            result = num1 / num2;
            break;
        }

        Serial.print("Result = ");
        Serial.println(result);
        delay(10000); 
        Serial.println("Enter first number:");
        currentState = WAIT_NUM1;
        break;
    }
  }
}
