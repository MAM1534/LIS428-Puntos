const int LED = 4;
const int FREQ_PWM = 5000;
const int RESOLUCION = 8;
const int PAUSA = 8;

void setup() {
  ledcAttach(LED, FREQ_PWM, RESOLUCION);
  Serial.begin(115200);
  Serial.println("*** E4: Fade in / Fade out ***");
}

void loop() {
  // Fade in: de apagado a máximo brillo
  for (int intensidad = 0; intensidad <= 255; intensidad++) {
    ledcWrite(LED, intensidad);
    Serial.print("Subiendo -> ");
    Serial.println(intensidad);
    delay(PAUSA);
  }

  // Fade out: de máximo brillo a apagado
  for (int intensidad = 255; intensidad >= 0; intensidad--) {
    ledcWrite(LED, intensidad);
    Serial.print("Bajando -> ");
    Serial.println(intensidad);
    delay(PAUSA);
  }
}