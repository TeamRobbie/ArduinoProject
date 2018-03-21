#include <IRSensoren.h>

#define IRSensorSelect0 6
#define IRSensorSelect1 5
#define IRSensorSelect2 4
#define IRSensor A1

//int *sensorWaardes;
//int currentMillis;

IRSensoren sensors(IRSensorSelect0,IRSensorSelect1,IRSensorSelect2,IRSensor);

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensors.readSensors();
  sensors.printWaardes();
  sensors.digitaliseer(300);
  sensors.printDigitaleWaardes();
  sensors.berekenFout();
  int factor = sensors.berekenPID();
  Serial.println(factor);
  delay(2000);
}
