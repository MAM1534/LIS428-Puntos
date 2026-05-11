#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);

  float lecturas[10];
  float suma = 0;

  for (int i = 0; i < 10; i++) {
    lecturas[i] = dht.readTemperature();
    Serial.print("Lectura "); Serial.print(i + 1);
    Serial.print(": "); Serial.println(lecturas[i]);
    suma += lecturas[i];
    delay(1500);
  }

  float promedio = suma / 10;
  Serial.print("Promedio: ");
  Serial.println(promedio);
}

void loop() {}