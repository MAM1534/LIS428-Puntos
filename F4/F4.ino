const int PIN_CAP = T3;  // GPIO15
int limiteDeteccion = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("*** F4: Calibracion de pin capacitivo ***");
  Serial.println("Mantén el pin libre, calibrando...");
  delay(2000);

  // Promedio de 10 muestras en reposo para definir el umbral
  long acumulado = 0;
  for (int j = 0; j < 10; j++) {
    acumulado += touchRead(PIN_CAP);
    delay(100);
  }

  int baseReposo = acumulado / 10;
  limiteDeteccion = baseReposo * 0.65;  // 65% del valor libre

  Serial.print("Base en reposo: ");
  Serial.println(baseReposo);
  Serial.print("Limite de deteccion: ");
  Serial.println(limiteDeteccion);
  Serial.println("Listo! Toca el pin para probar.");
}

void loop() {
  int muestra = touchRead(PIN_CAP);

  Serial.print("Lectura: ");
  Serial.print(muestra);
  Serial.print("  |  ");

  if (muestra < limiteDeteccion) {
    Serial.println(">> CONTACTO DETECTADO");
  } else {
    Serial.println("-- sin toque");
  }

  delay(250);
}