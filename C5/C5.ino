const int PIN_LIBRE = 32;
const int PIN_FIJO = 33;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== C5: Flotante vs Referencia ===");
  Serial.println("SinConexion | ConVoltaje");
}

void loop() {
  int sinConexion = analogRead(PIN_LIBRE);
  int conVoltaje  = analogRead(PIN_FIJO);

  Serial.print(sinConexion);
  Serial.print("  |  ");
  Serial.println(conVoltaje);

  delay(600);
}