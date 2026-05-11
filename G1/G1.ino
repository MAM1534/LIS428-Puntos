#include <Wire.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);  
  delay(1000);       
  Wire.begin();

  Serial.println("Escaneando bus I2C...");
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(addr, HEX);
    }
  }
  Serial.println("Escaneo completo.");
}

void loop() {}