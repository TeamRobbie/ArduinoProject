#include <IRSensoren.h>

#define IRSensorSelect0 1
#define IRSensorSelect1 2
#define IRSensorSelect2 3
#define IRSensor A1

int *sensorWaardes;
int currentMillis;

IRSensoren sensors(IRSensorSelect0,IRSensorSelect1,IRSensorSelect2,IRSensor);

void setup() {
  Serial.begin(9600);
}

void loop() {
  currentMillis= millis();
  sensorWaardes=sensors.readSensors();
  Serial.println(millis()-currentMillis);
  Serial.println("-----------------------------------------");
  for(int i = 0; i < 8; i++){
    Serial.print(sensorWaardes[i]);
    Serial.print("\t");
  }
  Serial.println();
}
