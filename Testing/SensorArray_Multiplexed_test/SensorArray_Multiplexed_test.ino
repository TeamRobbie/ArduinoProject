#define IRSensorSelect0 1
#define IRSensorSelect1 2
#define IRSensorSelect2 3
#define IRSensor A1


void setup() {
  pinMode(IRSensorSelect0,OUTPUT);
  pinMode(IRSensorSelect1,OUTPUT);
  pinMode(IRSensorSelect2,OUTPUT);
  pinMode(IRSensor,INPUT);

  Serial.begin(9600);

}

void loop() {
  //Sensor 1
  digitalWrite(IRSensorSelect0,LOW);
  digitalWrite(IRSensorSelect1,LOW);
  digitalWrite(IRSensorSelect2,LOW);
  int s1 = analogRead(IRSensor);
  //Sensor 2
  digitalWrite(IRSensorSelect0,HIGH);
  digitalWrite(IRSensorSelect1,LOW);
  digitalWrite(IRSensorSelect2,LOW);
  int s2 = analogRead(IRSensor);
  //Sensor 1
  digitalWrite(IRSensorSelect0,LOW);
  digitalWrite(IRSensorSelect1,HIGH);
  digitalWrite(IRSensorSelect2,LOW);
  int s3 = analogRead(IRSensor);
  //Sensor 1
  digitalWrite(IRSensorSelect0,HIGH);
  digitalWrite(IRSensorSelect1,HIGH);
  digitalWrite(IRSensorSelect2,LOW);
  int s4 = analogRead(IRSensor);
  //Sensor 1
  digitalWrite(IRSensorSelect0,LOW);
  digitalWrite(IRSensorSelect1,LOW);
  digitalWrite(IRSensorSelect2,HIGH);
  int s5 = analogRead(IRSensor);

  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);

}
