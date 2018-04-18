/*
	IRSensoren.cpp - Library for driving Robbie
	Jonas Bolle & Jorik De Bruycker
*/

#include "Arduino.h"
#include "IRSensoren.h"
#include "SoftwareSerial.h"

IRSensoren::IRSensoren(int s0, int s1, int s2, int analogInMidden, int analogInZij){
	//pinMode declarations
	pinMode(s0,OUTPUT);
	pinMode(s1,OUTPUT);
	pinMode(s2,OUTPUT);
	pinMode(analogInMidden,INPUT);
	pinMode(analogInZij,INPUT);
	// Channel select bits
	_s0 = s0;
	_s1 = s1;
	_s2 = s2;
	//Channel reset
	digitalWrite(_s0,LOW);
  digitalWrite(_s1,LOW);
  digitalWrite(_s2,LOW);
	//analogIn bepalen
	_analogInMidden = analogInMidden;
	_analogInZij = analogInZij;
	//Waardes voor PID-regeling initialiseren
	_waardesMidden = new int[8];
	_digitaleWaardesMidden = new int[8];
	_waardesZij = new int[8];
	_digitaleWaardesZij = new int[8];
	_aantalHoogLinks = 0;
	_aantalHoogMidden = 0;
	_aantalHoogRechts = 0;
	_factor = 0;
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
	_waardesMidden=[VDD, sens1, sens2, sens3, sens4, sens5, sensLinks, sensRechts]
	*/

	//Grey code 000 = 0 - pin 13 - sensor 3 - sensor Links 2
  digitalWrite(_s2,LOW);
  _waardesMidden[3] = analogRead(_analogInMidden);
	_waardesZij[1] = analogRead(_analogInZij);
  //Grey code 001 = 1 - pin 14 - sensor 4 - sensor Links 3
  digitalWrite(_s0,HIGH);
  _waardesMidden[4] = analogRead(_analogInMidden);
	_waardesZij[2] = analogRead(_analogInZij);
  //Grey code 011 = 3 - pin 12 - sensor 2 - sensor Links 1
  digitalWrite(_s1,HIGH);
  _waardesMidden[2] = analogRead(_analogInMidden);
	_waardesZij[0] = analogRead(_analogInZij);
  //Grey code 010 = 2 - pin 15 - sensor 5 - sensor Links 4
  digitalWrite(_s0,LOW);
  _waardesMidden[5] = analogRead(_analogInMidden);
	_waardesZij[3] = analogRead(_analogInZij);
  //Grey code 110 = 6 - pin 2 - GND - sensor Rechts 2
  digitalWrite(_s2,HIGH);
  _waardesMidden[0] = analogRead(_analogInMidden);
	_waardesZij[5] = analogRead(_analogInZij);
  //Grey code 111 = 7 - pin 4 - sensor 1 - sensor Rechts 3
  digitalWrite(_s0,HIGH);
  _waardesMidden[1] = analogRead(_analogInMidden);
	_waardesZij[6] = analogRead(_analogInZij);
	//Grey code 101 = 5 - pin 5 - sensor Links - sensor Rechts 4
  digitalWrite(_s1,LOW);
  _waardesMidden[6] = analogRead(_analogInMidden);
	_waardesZij[7] = analogRead(_analogInZij);
  //Grey code 100 = 4 - pin 1 - sensor Rechts - sensor Rechts 1
  digitalWrite(_s0,LOW);
  _waardesMidden[7] = analogRead(_analogInMidden);
	_waardesZij[4] = analogRead(_analogInZij);
}

void IRSensoren::printWaardes(SoftwareSerial bt){
	/* Deze methode kan gebruikt worden bij het testen om de waardes te monitoren
	met behulp van de seriele monitor */
	/*for(int i=0; i < 8; i++) {
		Serial.print(_waardesMidden[i]);
		Serial.print('\t');
	}
	Serial.println();*/
	for(int i=0; i < 8; i++) {
		bt.print(_waardesZij[i]);
		bt.print('\t');
	}
	bt.println();
	bt.println("----------------------------------------------");
}

void IRSensoren::printDigitaleWaardes(SoftwareSerial bt){
	/* Deze methode kan gebruikt worden bij het testen om de digitale waardes te
	monitoren met behulp van de seriele monitor */
	/*for(int i=0; i < 8; i++) {
		bt.print(_digitaleWaardesMidden[i]);
		bt.print('\t');
	}
	bt.println();*/
	for(int i=0; i < 8; i++) {
		bt.print(_digitaleWaardesZij[i]);
		bt.print('\t');
	}
	bt.println();
	bt.println("----------------------------------------------");
}

void IRSensoren::digitaliseer(int grens){
	/*Deze methode zet de analoog ingelezen waardes om in digitale waardes
	afhankelijk van een meegegeven grens */

	for(int i=0; i< 8; i++) {
		/*
		if(_waardesMidden[i] > grens) {
			_digitaleWaardesMidden[i] = 0;
		}
		else {
			_digitaleWaardesMidden[i] = 1;
		}
		*/

		if(_waardesZij[i] > grens) {
			_digitaleWaardesZij[i] = 0;
		}
		else {
			_digitaleWaardesZij[i] = 1;
		}
	}
}

int IRSensoren::berekenPID(int KP, int KI, int KD){
	/*Deze methode berekent de fout ten opzichte van de middenlijn
	Te veel naar links geeft negatieve fout
	Te veel naar rechts geeft een positieve fout
	Vervolgens wordt een PID-factor berekend aan de hand van deze fout*/
	_vorigeError = _error;
	_error = 0;

	/*
	//5 middelste sensoren
	_aantalHoogMidden = 0;
	for(int i = 1; i<=5; i++) {
		if(_digitaleWaardesMidden[i] == 1) _aantalHoogMidden++;
	}
	if (_aantalHoogMidden != 0) {
		_error += (-4*_digitaleWaardesMidden[1]-2*_digitaleWaardesMidden[2]+2*_digitaleWaardesMidden[4]+4*_digitaleWaardesMidden[5])/_aantalHoogMidden;
	}
	*/

	//Linksvoor
	_aantalHoogLinks = 0;
	for(int i = 0; i<=3; i++) {
		if(_digitaleWaardesZij[i] == 1) _aantalHoogLinks++;
	}
	//Linksachter
	_aantalHoogRechts = 0;
	for(int i = 4; i<=7; i++) {
		if(_digitaleWaardesZij[i] == 1) _aantalHoogRechts++;
	}

	if(_aantalHoogLinks != 0) {
		//Linksvoor
		_error +=(-3*_digitaleWaardesZij[0]-1*_digitaleWaardesZij[1]+1*_digitaleWaardesZij[2]+3*_digitaleWaardesZij[3])/_aantalHoogLinks;
		_errorVooraan = _error;
		//Linksachter
		_error +=(3*_digitaleWaardesZij[7]+1*_digitaleWaardesZij[6]-1*_digitaleWaardesZij[5]-3*_digitaleWaardesZij[4])/_aantalHoogRechts;
	}
	else {
		if(_errorVooraan < 0) {
			_error = _vorigeError - 1;
		}
		else if (_errorVooraan > 0) {
			_error = _vorigeError + 1;
		}
	}

	_P = _error;
	_I = _I + _error;
	_D = _error - _vorigeError;
	_I = constrain(_I, -10, 10);

	_factor =  KP * _P + KI * _I + KD * _D;
	_factor = constrain(_factor, -100, 100);
	return _factor;
}
