#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid     = "AndroidAP7495";
const char* password = "7070buho";

const char* mqtt_server = "broker.hivemq.com";
const int   mqtt_port   = 1883;
const char* topic       = "escuela/led/control";

#define LED 5

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String mensaje = "";
  for (int i = 0; i < length; i++) {
    mensaje += (char)payload[i];
  }
  mensaje.trim(); 

  Serial.print("Mensaje recibido: '");
  Serial.print(mensaje);
  Serial.println("'");
  Serial.print("Longitud: ");
  Serial.println(mensaje.length());

  if (mensaje == "ON") {
    digitalWrite(LED, HIGH);
    Serial.println("LED encendido");
  } else if (mensaje == "OFF") {
    digitalWrite(LED, LOW);
    Serial.println("LED apagado");
  } else {
    Serial.println("Mensaje no reconocido");
  }
}

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
    String clientId = "ESP32LED_" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("conectado!");
      client.subscribe(topic);
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
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  conectarWiFi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  client.setKeepAlive(60);
  conectarMQTT();
}

void loop() {
  if (!client.connected()) conectarMQTT();
  client.loop();
  delay(10);
}