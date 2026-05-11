#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid     = "AndroidAP7495";
const char* password ="7070buho";

const char* mqtt_server = "broker.hivemq.com";
const int   mqtt_port   = 1883;
const char* topic       = "escuela/sensor/temperatura";

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long ultimaLectura = 0;  
const long intervalo = 5000;      

void conectarWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(1000);
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
    String clientId = "ESP32DHT_" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("conectado!");
    } else {
      Serial.print("Error: ");
      Serial.println(client.state());
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(3000);
  dht.begin();
  conectarWiFi();
  client.setServer(mqtt_server, mqtt_port);
  client.setKeepAlive(60);
  conectarMQTT();
}

void loop() {
  if (!client.connected()) conectarMQTT();
  client.loop();

  unsigned long ahora = millis();  

  if (ahora - ultimaLectura >= intervalo) {
    ultimaLectura = ahora;

    float temp = dht.readTemperature();

    if (!isnan(temp)) {
      // Arma el mensaje con timestamp
      char mensaje[50];
      sprintf(mensaje, "%.2f°C | t=%lums", temp, ahora);

      client.publish(topic, mensaje);
      Serial.print("Publicado: ");
      Serial.println(mensaje);
    }
  }
}