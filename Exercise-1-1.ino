void setup() 
{
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  analogReadResolution(12);
}

void loop() 
{
  digitalWrite(6, HIGH);
  delay(500); 
  digitalWrite(6, LOW);
  delay(500);     

  int sensorValue = analogRead(A1);
  Serial.println(sensorValue);
  delay(1000);
  
}
