const int CAP_PIN = T3;       // GPIO15
const int LUZ_PIN = 4;
const int LIMITE = 750;
const int VENTANA_DOBLE = 350;  // ms máximos entre dos toques

bool luzActiva = false;
bool esperandoSegundo = false;
unsigned long marcaPrimerToque = 0;

void setup() {
  pinMode(LUZ_PIN, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  Serial.println("*** F5: Toggle con doble toque ***");
  Serial.println("Da dos toques rapidos para encender/apagar el LED");
}

void loop() {
  int captado = touchRead(CAP_PIN);

  if (captado < LIMITE) {
    if (!esperandoSegundo) {
      // Registro del primer toque
      esperandoSegundo = true;
      marcaPrimerToque = millis();
      Serial.println("1er toque registrado...");
      delay(200);

    } else {
      // Segundo toque detectado
      if (millis() - marcaPrimerToque < VENTANA_DOBLE) {
        luzActiva = !luzActiva;
        digitalWrite(LUZ_PIN, luzActiva);
        Serial.print("Doble toque confirmado! -> LED ");
        Serial.println(luzActiva ? "ON" : "OFF");
      }
      esperandoSegundo = false;
      delay(200);
    }
  }

  // Ventana de tiempo expirada, reiniciar espera
  if (esperandoSegundo && millis() - marcaPrimerToque > VENTANA_DOBLE) {
    esperandoSegundo = false;
    Serial.println("Tiempo vencido, intenta de nuevo.");
  }

  delay(10);
}