#include <WiFiNINA.h>

void setup() 
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Starting WiFi scanner (interval: 30 seconds)...");
}

void loop() 
{
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WiFi module not found!");
    while (true);
}

  Serial.println("\nScanning available networks...");

  uint8_t numNetworks = WiFi.scanNetworks();
  if (numNetworks == 255) { 
    Serial.println("WiFi scan failed. Retrying in 30 seconds...");
    delay(30000);
    return;
  }

  for (uint8_t i = 0; i < numNetworks; i++) {
    Serial.print("Network ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" | Signal Strength: ");
    Serial.print(WiFi.RSSI(i));
    Serial.print(" dBm | Encryption: ");
    Serial.println(WiFi.encryptionType(i));
  }

  Serial.print("Total networks found: ");
  Serial.println(numNetworks);

  Serial.println("\nWaiting 30 seconds before next scan...\n");
  delay(30000);
}
