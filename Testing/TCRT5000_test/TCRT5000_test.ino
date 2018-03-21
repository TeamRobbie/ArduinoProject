#define IRSensor A1

void setup() {
  pinMode(IRSensor,INPUT);
  Serial.begin(9600);

}

void loop() {
  int waarde = analogRead(IRSensor);
  Serial.println(waarde);
  delay(500);
}
