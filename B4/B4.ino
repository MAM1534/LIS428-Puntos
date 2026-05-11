const int LED_PIN = 15;
const long PERIODO = 1000;

unsigned long marcaTiempo = 0;
bool luzEncendida = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("--- B4: Control de LED no bloqueante ---");
}

void loop() {
  unsigned long ahora = millis();

  if (ahora - marcaTiempo >= PERIODO) {
    marcaTiempo = ahora;
    luzEncendida = !luzEncendida;
    digitalWrite(LED_PIN, luzEncendida);

    Serial.print("Estado del LED -> ");
    Serial.println(luzEncendida ? "ON" : "OFF");
  }

  // El loop sigue libre para otras tareas mientras espera
}