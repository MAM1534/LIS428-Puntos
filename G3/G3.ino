#include <Wire.h>
#include <BH1750.h>

BH1750 sensor;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  sensor.begin();
  Serial.println("BH1750 listo");
}

void loop() {
  float lux = sensor.readLightLevel();
  Serial.print("Luz: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}