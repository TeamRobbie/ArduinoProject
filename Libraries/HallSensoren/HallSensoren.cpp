/*
	HallSensoren.cpp - Library for driving Robbie
	Jonas Bolle & Jorik De Bruycker
*/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "HallSensoren.h"

HallSensoren::HallSensoren(int digitalePin) {
  pinMode(digitalePin, INPUT);
  _digitalePin = digitalePin;
  _status = digitalRead(_digitalePin);
  _vorigeStatus = _status;
  _geprint = false;
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

void HallSensoren::printSpeed(SoftwareSerial bt) {
  if(millis() % 10000 > 1000) _geprint = false;
  if(millis() % 10000 < 10 && !_geprint) {
    //Aantal keer gepasseerd *pi *diameter / 2 magneten
    float deltaX = _count*3.14*7/100/2;
    float deltaT = 10;
    bt.print("Aantal magneten gepasseerd:  ");
    bt.println(_count);
    _count = 0;
    _speed = deltaX / deltaT;
    bt.print(_speed);
    bt.println("   m/s");
    _geprint = true;
  }
}
