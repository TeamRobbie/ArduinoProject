/*
	IRSensoren.h - Library for driving Robbie.
	Jonas Bolle & Jorik De Bruycker
*/

#ifndef IRSensoren_h
#define IRSensoren_h

#include "Arduino.h"

class IRSensoren{
	public:
		//Constructor
		IRSensoren(int s0, int s1, int s2, int analogIn);

		//Methodes
		void readSensors();
		void printWaardes();
		void printDigitaleWaardes();
		void digitaliseer(int grens);
		int berekenPID();
	private:
		// Channel select bits
		int _s0;
  	int _s1;
  	int _s2;
		// Analog read channel
  	int _analogIn;
		// Ingelezen en verwerkte waardes
    int * _waardes;
		int * _digitaleWaardes;
		// Fout en PID-waardes
		int _aantalHoog;
		int _error;
		int _vorigeError;
		int _P;
		int _I;
		int _D;

};


#endif
