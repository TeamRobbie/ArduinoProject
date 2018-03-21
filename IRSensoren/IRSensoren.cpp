/*
	IRSensoren.cpp - Library for driving Robbie
	Jonas Bolle & Jorik De Bruycker
*/

#include "Arduino.h"
#include "IRSensoren.h"

IRSensoren::IRSensoren(int s0, int s1, int s2, int analogIn){
	//pinMode declarations
	pinMode(s0,OUTPUT);
	pinMode(s1,OUTPUT);
	pinMode(s2,OUTPUT);
	pinMode(analogIn,INPUT);
	// Channel select bits
	_s0 = s0;
	_s1 = s1;
	_s2 = s2;
	//Channel reset
	digitalWrite(_s0,LOW);
  digitalWrite(_s1,LOW);
  digitalWrite(_s2,LOW);
	//analogIn bepalen
	_analogIn = analogIn;
	//Waardes voor PID-regeling initialiseren
	_waardes = new int[8];
	_digitaleWaardes = new int[8];
	_aantalHoog = 0;
	_P = 0;
	_I = 0;
	_D = 0;
	_error = 0;
	_vorigeError = 0;
}

void IRSensoren::readSensors(){
  /*Sensoren worden overlopen mbv Grey-code en er moet rekening gehouden worden
	met de sensorarray-hardware voor het inlezen
	We lezen de resultaten in als volgt:
	_waardes=[VDD, sens1, sens2, sens3, sens4, sens5, sensLinks, sensRechts]
	*/

	//Grey code 000 = 0 - pin 13 - sensor 3
  digitalWrite(_s2,LOW);
  _waardes[3] = analogRead(_analogIn);
  //Grey code 001 = 1 - pin 14 - sensor 4
  digitalWrite(_s0,HIGH);
  _waardes[4] = analogRead(_analogIn);
  //Grey code 011 = 3 - pin 12 - sensor 2
  digitalWrite(_s1,HIGH);
  _waardes[2] = analogRead(_analogIn);
  //Grey code 010 = 2 - pin 15 - sensor 5
  digitalWrite(_s0,LOW);
  _waardes[5] = analogRead(_analogIn);
  //Grey code 110 = 6 - pin 2 - VDD
  digitalWrite(_s2,HIGH);
  _waardes[0] = analogRead(_analogIn);
  //Grey code 111 = 7 - pin 4 - sensor 1
  digitalWrite(_s0,HIGH);
  _waardes[1] = analogRead(_analogIn);
	//Grey code 101 = 5 - pin 5 - sensor Links
  digitalWrite(_s1,LOW);
  _waardes[6] = analogRead(_analogIn);
  //Grey code 100 = 4 - pin 1 - sensor Rechts
  digitalWrite(_s0,LOW);
  _waardes[7] = analogRead(_analogIn);
}

void IRSensoren::printWaardes(){
	/* Deze methode kan gebruikt worden bij het testen om de waardes te monitoren
	met behulp van de seriele monitor */
	for(int i=0; i < 8; i++) {
		Serial.print(_waardes[i]);
		Serial.print('\t');
	}
	Serial.println();
	Serial.println("----------------------------------------------");
}

void IRSensoren::printDigitaleWaardes(){
	/* Deze methode kan gebruikt worden bij het testen om de digitale waardes te
	monitoren met behulp van de seriele monitor */
	for(int i=0; i < 8; i++) {
		Serial.print(_digitaleWaardes[i]);
		Serial.print('\t');
	}
	Serial.println();
	Serial.println("----------------------------------------------");
}

void IRSensoren::digitaliseer(int grens){
	/*Deze methode zet de analoog ingelezen waardes om in digitale waardes
	afhankelijk van een meegegeven grens */
	for(int i=0; i< 8; i++) {
		if(_waardes[i] > grens) {
			_digitaleWaardes[i] = 0;
		}
		else _digitaleWaardes[i] = 1;
	}
}

int IRSensoren::berekenPID(){
	/*Deze methode berekent de fout ten opzichte van de middenlijn
	Te veel naar links geeft negatieve fout
	Te veel naar rechts geeft een positieve fout
	Vervolgens wordt een PID-factor berekend aan de hand van deze fout*/
	_vorigeError = _error;
	_aantalHoog = 0;
	//5 middelste sensoren
	for(int i = 1; i<=7; i++) {
		if(_digitaleWaardes[i] == 1) _aantalHoog++;
	}
	if (_aantalHoog != 0) {
		_error = (-4*_digitaleWaardes[1]-2*_digitaleWaardes[2]+2*_digitaleWaardes[4]+4*_digitaleWaardes[5]);
		//linkerarm
		_error -= 6*_digitaleWaardes[6];
		//rechterarm
		_error += 6*_digitaleWaardes[7];
		_error = _error/_aantalHoog;
	}

	_P = _error;
	_I = _I + _error;
	_D = _error - _vorigeError;
	_I = constrain(_I, -10, 10);

	int _KP = 20;
	int _KI = 0;
	int _KD = 5;
	int factor =  _KP * _P + _KI * _I + _KD * _D;
	factor = constrain(factor, -100, 100);
	return factor;
}
