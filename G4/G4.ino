#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

BH1750 sensorLuz(0x5C);  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  sensorLuz.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x5C);  
  dht.begin();
  delay(2000);
  Serial.println("Luz (lx) | Temp (°C) | Hum (%)");
  Serial.println("---------|-----------|--------");
}

void loop() {
  float lux  = sensorLuz.readLightLevel();
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  Serial.print(lux);  Serial.print(" lx   | ");
  Serial.print(temp); Serial.print(" °C     | ");
  Serial.print(hum);  Serial.println(" %");

  delay(1000);
}