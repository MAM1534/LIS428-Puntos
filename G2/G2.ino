#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Error leyendo DHT");
    return;
  }

  Serial.print("Temp: "); Serial.print(temp); Serial.println(" °C");
  Serial.print("Hum:  "); Serial.print(hum);  Serial.println(" %");
  delay(2000);
}