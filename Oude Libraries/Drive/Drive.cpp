/*
	Drive.cpp - Library for driving Robbie
	Jonas Bolle & Jorik De Bruycker
*/

#include "Arduino.h"
#include "Drive.h"

Drive::Drive(int rA, int rB, int snA, int snB){
	//_rA bepaalt de richting van de linkse motor, 0= vooruit, 1 = achteruit
	//_rB bepaalt de richting van de rechtse moto, 1 = vooruit, 0 = achteruit
	pinMode(rA,OUTPUT);
	pinMode(rB,OUTPUT);
	pinMode(snA,OUTPUT);
	pinMode(snB,OUTPUT);
	_rA = rA;
	_rB = rB;
	_snA = snA;
	_snB = snB;
}

void Drive::drive(char sel, int factor){
	//Voorlopig nog veel gefoefel in methode afhankelijk van verschil op motoren bij testen, te verbeteren
	_currentMillis = millis();
  	switch(sel){

    		case 'F':
      			_factorA = factor;
      			_factorB = factor - (factor/10);
      			digitalWrite(_rA,HIGH);
      			digitalWrite(_rB,LOW);
      			while(millis() - _currentMillis <= 1500 && _factorB >=0){
      				analogWrite(_snB,_factorB);
      				//delay(10); //linkerwiel startte steeds iets sneller dan rechterwiel
      				analogWrite(_snA,_factorA);
      			}
      			break;

    		case 'L': //factor moet hier minstents 50 zijn
      			_factorA = factor - (factor/3);
      			_factorB = factor;
      			digitalWrite(_rA,HIGH);
      			digitalWrite(_rB,LOW);
      			while(millis() - _currentMillis <= 1500){
      				analogWrite(_snA,_factorA);
      				analogWrite(_snB,_factorB);
      			}
      			break;

    		case 'R': //factor moet hier minstens 50 zijn
      			_factorA = factor;
      			_factorB = factor - (factor/3);
      			digitalWrite(_rA,HIGH);
     			digitalWrite(_rB,LOW);
     			while(millis() - _currentMillis <= 1500){
        			analogWrite(_snA,_factorA);
        			analogWrite(_snB,_factorB);
      			}
      			break;

    		case 'B':
      			_factorA = factor;
      			_factorB = factor - (factor/10);
      			digitalWrite(_rA,LOW);
      			digitalWrite(_rB,HIGH);
      			while(millis() - _currentMillis <= 1500 && _factorB >=0){
      				analogWrite(_snB,_factorB);
        			//delay(10); //linkerwiel startte steeds iets sneller dan rechterwiel
        			analogWrite(_snA,_factorA);
      			}
      			break;
    	}
  	analogWrite(_snA,0);
  	analogWrite(_snB,0);
}

void Drive::driveScale(int snelheid, int schaal) {
	//Functie met schaalfactor van -100 tot 100, -100=volledig links, 0=rechtdoor, 100=volledig rechts
	digitalWrite(_rA,LOW);
	digitalWrite(_rB,HIGH);
	switch(schaal) {
		case -100 ... -1:
			analogWrite(_snA, snelheid - snelheid * abs(schaal)/100);
			analogWrite(_snB, snelheid);
			break;
		case 0:
			analogWrite(_snA, snelheid);
			analogWrite(_snB, snelheid);
			break;
		case 1 ... 100:
			analogWrite(_snA, snelheid);
			analogWrite(_snB, snelheid - snelheid * schaal/100);
			break;
	}
}

void Drive::driveCorrectieLR(int snelheid, int correctie) {
	analogWrite(_snA, snelheid + correctie);
	analogWrite(_snB, snelheid - correctie);
}
