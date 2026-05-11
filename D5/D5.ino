#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("*** D5: Scanner de redes WiFi ***");
}

void loop() {
  Serial.println("\n>> Escaneando redes disponibles...");
  int totalRedes = WiFi.scanNetworks();

  if (totalRedes == 0) {
    Serial.println("Sin redes detectadas en el area.");
  } else {
    Serial.print("Redes encontradas: ");
    Serial.println(totalRedes);
    Serial.println("================================");
    Serial.println("  #  |        SSID        | RSSI  | Canal");
    Serial.println("================================");

    for (int n = 0; n < totalRedes; n++) {
      Serial.print("  ");
      Serial.print(n + 1);
      Serial.print("  |  ");
      Serial.print(WiFi.SSID(n));
      Serial.print("  |  ");
      Serial.print(WiFi.RSSI(n));
      Serial.print(" dBm  |  ch.");
      Serial.println(WiFi.channel(n));
    }
    Serial.println("================================");
  }

  Serial.println("Siguiente escaneo en 5 s...\n");
  delay(5000);
}