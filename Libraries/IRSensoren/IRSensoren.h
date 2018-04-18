/*
	IRSensoren.h - Library for driving Robbie.
	Jonas Bolle & Jorik De Bruycker
*/

#ifndef IRSensoren_h
#define IRSensoren_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class IRSensoren{
	public:
		//Constructor
		IRSensoren(int s0, int s1, int s2, int analogInMidden, int analogInZij);

		//Methodes
		void readSensors();
		void printWaardes(SoftwareSerial bt);
		void printDigitaleWaardes(SoftwareSerial bt);
		void digitaliseer(int grens);
		int berekenPID(int KP, int KI, int KD);
	private:
		//Attributen

		// Channel select bits
		int _s0;
  	int _s1;
  	int _s2;
		// Analog read channel
  	int _analogInMidden;
		int _analogInZij;
		// Ingelezen en verwerkte waardes
    int * _waardesMidden;
		int * _digitaleWaardesMidden;
		int * _waardesZij;
		int * _digitaleWaardesZij;
		// Fout en PID-waardes
		int _aantalHoogLinks;
		int _aantalHoogMidden;
		int _aantalHoogRechts;
		int _factor;
		int _error;
		int _errorVooraan;
		int _vorigeError;
		int _P;
		int _I;
		int _D;

};


#endif
