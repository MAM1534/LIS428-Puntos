// --- Configuración inicial ---
const int LED_PIN = 2;

int pwmFreq = 5000;
int pwmResolution = 8;
int brilloLED = 128;

// --- Función para actualizar PWM ---
void configurarPWM() {
  ledcAttach(LED_PIN, pwmFreq, pwmResolution);
  ledcWrite(LED_PIN, brilloLED);
}

// --- Setup ---
void setup() {
  Serial.begin(115200);
  delay(2000);

  configurarPWM();
}

// --- Loop ---
void loop() {
  if (Serial.available() > 0) {
    String texto = Serial.readStringUntil('\n');
    texto.trim();

    if (texto.startsWith("b")) {
      brilloLED = constrain(texto.substring(1).toInt(), 0, 255);
      ledcWrite(LED_PIN, brilloLED);
      Serial.println(brilloLED);

    } else if (texto.startsWith("p")) {
      pwmFreq = texto.substring(1).toInt();
      configurarPWM();
      Serial.println(pwmFreq);
    }
  }
}