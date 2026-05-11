const int ADC_PIN = 36;
int muestras = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Valor"); 

void loop() {
  if (muestras < 20) {
    int valor = analogRead(ADC_PIN);
    Serial.println(valor);
    muestras++;
    delay(800);
  }
}