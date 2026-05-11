// ===== B5 - Secuencia de 3 LEDs con millis() =====
// ESP32

const int LED_ROJO = 2;
const int LED_AMARILLO = 4;
const int LED_VERDE = 5;

// Variables de tiempo
unsigned long tiempoRojo = 0;
unsigned long tiempoAmarillo = 0;
unsigned long tiempoVerde = 0;

// Estados
bool estadoRojo = LOW;
bool estadoAmarillo = LOW;
bool estadoVerde = LOW;

// Control especial del LED verde
int contadorVerde = 0;

void setup() {

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  Serial.begin(115200);

  Serial.println("=== PRACTICA B5 ===");
  Serial.println("3 LEDs con patrones distintos usando millis()");
}

void loop() {

  unsigned long actual = millis();

  // ===== LED ROJO =====
  // Parpadeo rápido cada 300 ms
  if (actual - tiempoRojo >= 300) {

    tiempoRojo = actual;

    estadoRojo = !estadoRojo;

    digitalWrite(LED_ROJO, estadoRojo);

    Serial.println("Rojo parpadeando rapido");
  }

  // ===== LED AMARILLO =====
  // Parpadeo lento cada 1000 ms
  if (actual - tiempoAmarillo >= 1000) {

    tiempoAmarillo = actual;

    estadoAmarillo = !estadoAmarillo;

    digitalWrite(LED_AMARILLO, estadoAmarillo);

    Serial.println("Amarillo parpadeando lento");
  }

  // ===== LED VERDE =====
  // Doble destello
  if (actual - tiempoVerde >= 200) {

    tiempoVerde = actual;

    estadoVerde = !estadoVerde;

    digitalWrite(LED_VERDE, estadoVerde);

    contadorVerde++;

    // Después de 2 parpadeos espera más tiempo
    if (contadorVerde >= 4) {

      contadorVerde = 0;

      tiempoVerde = actual + 1000;
    }

    Serial.println("Verde haciendo doble destello");
  }
}