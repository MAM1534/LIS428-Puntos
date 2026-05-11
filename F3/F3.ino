const int TACTIL = T3;  // GPIO15

void setup() {
  Serial.begin(115200);
  delay(1500);
  Serial.println("*** F3: Monitor de pin tactil ***");
  Serial.println("Toca y suelta el pin para ver cambios");
}

void loop() {
  int lecturaTactil = touchRead(TACTIL);

  Serial.print("Pin tactil -> ");
  Serial.println(lecturaTactil);

  delay(250);
}