const bool MODO_PESADO = false;  
unsigned long t_arranque;
unsigned long t_cierre;
unsigned long transcurrido;
int iteracion = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("*** A5: Benchmark de tiempo por iteracion del loop ***");

  if (MODO_PESADO) {
    Serial.println("Configuracion actual: loop CON operaciones");
  } else {
    Serial.println("Configuracion actual: loop VACIO");
  }
  Serial.println("---------------------------------------------");
}

void loop() {
  t_arranque = micros();

  if (MODO_PESADO) {
    // Operaciones que consumen tiempo de CPU
    int acumulador = 0;
    for (int k = 0; k < 1000; k++) {
      acumulador += k;
    }

    float resultado = sqrt(98765.432);
    int lectura = analogRead(34);

    // Evitar que el compilador elimine las variables por optimización
    (void)acumulador;
    (void)resultado;
    (void)lectura;
  }

  t_cierre = micros();
  transcurrido = t_cierre - t_arranque;
  iteracion++;

  Serial.print("Iter ");
  Serial.print(iteracion);
  Serial.print("  ->  tiempo: ");
  Serial.print(transcurrido);
  Serial.println(" us");

  delay(500);
}