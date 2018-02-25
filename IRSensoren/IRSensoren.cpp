/*
	IRSensoren.cpp - Library for driving Robbie
	Jonas Bolle & Jorik De Bruycker
*/

#include "Arduino.h"
#include "IRSensoren.h"

IRSensoren::IRSensoren(int s0, int s1, int s2, int analogIn){
	pinMode(s0,OUTPUT);
	pinMode(s1,OUTPUT);
	pinMode(s2,OUTPUT);
	pinMode(analogIn,INPUT);
  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
	_s0 = s0;
	_s1 = s1;
	_s2 = s2;
	_analogIn = analogIn;
	//_waardes = new int[8];
}

int * IRSensoren::readSensors(){
  //We lezen sensoren in adhv Grey code
	static int _waardes[8];
	//Sensor 1 -- Grey code 000
  digitalWrite(_s2,LOW);
  _waardes[0] = analogRead(_analogIn);
  //Sensor 2 -- Grey code 001
  digitalWrite(_s0,HIGH);
  _waardes[1] = analogRead(_analogIn);
  //Sensor 3 -- Grey code 011
  digitalWrite(_s1,HIGH);
  _waardes[2] = analogRead(_analogIn);
  //Sensor 4 -- Grey code 010
  digitalWrite(_s0,LOW);
  _waardes[3] = analogRead(_analogIn);
  //Sensor 5 -- Grey code 110
  digitalWrite(_s2,HIGH);
  _waardes[4] = analogRead(_analogIn);
  //Sensor 6 -- Grey code 111
  digitalWrite(_s0,HIGH);
  _waardes[5] = analogRead(_analogIn);
  //Sensor 7 -- Grey code 101
  digitalWrite(_s1,LOW);
  _waardes[6] = analogRead(_analogIn);
  //Sensor 8 -- Grey code 100
  digitalWrite(_s0,LOW);
  _waardes[7] = analogRead(_analogIn);

	return(_waardes);
}
