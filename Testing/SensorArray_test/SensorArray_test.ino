#define IRSensor1 A1
#define IRSensor2 A2
#define IRSensor3 A3
#define IRSensor4 A4
#define IRSensor5 A5


void setup() {
  pinMode(IRSensor1,INPUT);
  pinMode(IRSensor2,INPUT);
  pinMode(IRSensor3,INPUT);
  pinMode(IRSensor4,INPUT);
  pinMode(IRSensor5,INPUT);

  Serial.begin(9600);

}

void loop() {
  int s1 = analogRead(IRSensor1);
  int s2 = analogRead(IRSensor2);
  int s3 = analogRead(IRSensor3);
  int s4 = analogRead(IRSensor4);
  int s5 = analogRead(IRSensor5);
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);

}
