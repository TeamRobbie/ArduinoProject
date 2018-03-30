#include <Drive.h>
#include <IRSensoren.h>
#include <HallSensoren.h>

//Motorsturing
#define richtingA 12
#define richtingB 13
#define snelheidA 3
#define snelheidB 11

//IR-sensoren
#define IRSensorSelect0 6
#define IRSensorSelect1 5
#define IRSensorSelect2 4
#define IRSensorOutMidden A1
#define IRSensorOutZij A0


//Hall-Sensor
#define hallSensorRead 7

Drive drive(richtingA,richtingB,snelheidA,snelheidB);

IRSensoren IRsensors(IRSensorSelect0, IRSensorSelect1, IRSensorSelect2, IRSensorOutMidden, IRSensorOutZij);

HallSensoren hallSensor(hallSensorRead);

int speed = 60;
void setup() {
  //Serial.begin(9600);
  digitalWrite(richtingA,LOW);
  digitalWrite(richtingB,HIGH);
}

void loop() {
  IRsensors.readSensors();
  IRsensors.digitaliseer(300);
  //IRsensors.printWaardes();
  //IRsensors.printDigitaleWaardes();
  //delay(500);
  int factor = IRsensors.berekenPID();
  drive.driveCorrectieLR(speed,speed*factor/100);
  //hallSensor.readSensors();
  //hallSensor.calculateSpeed();

}
