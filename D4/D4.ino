 const int CANAL_ADC = 36;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("*** D4: map() y constrain() combinados ***");
  Serial.println("Crudo | Mapeado | Acotado");
}

void loop() {
  int lectura    = analogRead(CANAL_ADC);
  int convertido = map(lectura, 0, 4095, 0, 255);
  int limitado   = constrain(convertido, 40, 210);

  Serial.print(lectura);
  Serial.print("  |  ");
  Serial.print(convertido);
  Serial.print("  |  ");
  Serial.println(limitado);

  delay(600);
}