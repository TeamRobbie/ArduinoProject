/*
	HallSensoren.cpp - Library for driving Robbie
	Jonas Bolle & Jorik De Bruycker
*/

#include "Arduino.h"
#include "HallSensoren.h"

HallSensoren::HallSensoren(int digitalePin) {
  pinMode(digitalePin, INPUT);
  _digitalePin = digitalePin;
  _status = digitalRead(_digitalePin);
  _vorigeStatus = _status;
  _count=0;
  _speed=0.0;
}

void HallSensoren::readSensors() {
  _vorigeStatus = _status;
  _status = digitalRead(_digitalePin);

  if (_status != _vorigeStatus) {
    _count++;
  }
}

void HallSensoren::calculateSpeed() {
  if(millis() % 10000 < 2) {
    //Aantal keer gepasseerd *pi *diameter / 2 / 4 magneten
    float deltaX = _count*3.14*7/100/2/2;
    float deltaT = 10;
    Serial.print("Aantal keer gepasseerd:  ");
    Serial.println(_count);
    _count = 0;
    _speed = deltaX / deltaT;
    Serial.print(_speed);
    Serial.println("   m/s");
  }
}
