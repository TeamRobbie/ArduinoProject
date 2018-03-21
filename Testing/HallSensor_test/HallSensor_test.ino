void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(7);
  Serial.println(reading);
  delay(100);
}
