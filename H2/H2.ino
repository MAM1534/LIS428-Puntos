#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid     = "AndroidAP7495";
const char* password = "7070buho";

const char* mqtt_server = "broker.hivemq.com";
const int   mqtt_port   = 1883;
const char* topic       = "escuela/sensor/temperatura"; 

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

void conectarWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void conectarMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado!");
    } else {
      Serial.print("Error: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(3000);
  dht.begin();
  conectarWiFi();
  client.setServer(mqtt_server, mqtt_port);
  conectarMQTT();
}

void loop() {
  if (!client.connected()) conectarMQTT();
  client.loop();

  float temp = dht.readTemperature();

  if (!isnan(temp)) {
    char mensaje[10];
    dtostrf(temp, 4, 2, mensaje);
    client.publish(topic, mensaje);
    Serial.print("Publicado: ");
    Serial.println(mensaje);
  }

  delay(3000);
}