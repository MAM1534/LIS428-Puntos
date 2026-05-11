#include <WiFi.h>

const char* ssid     = "AndroidAP7495";
const char* password =  "7070buho";

void setup() {
  Serial.begin(115200);
  delay(3000);

  WiFi.begin(ssid, password);
  Serial.print("Conectando");

  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 30) {
    delay(1000);
    Serial.print(".");
    intentos++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi conectado!");
    Serial.print("IP asignada: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("");
    Serial.println("No se pudo conectar, señal débil.");
  }
}

void loop() {}