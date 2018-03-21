/*
	Drive.h - Library for driving Robbie.
	Jonas Bolle & Jorik De Bruycker
*/

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Drive{
	public:
		Drive(int rA, int rB, int snA, int snB);
		void drive(char sel, int factor);
		void driveScale(int snelheid, int schaal);
		void driveCorrectieLR(int snelheid, int correctie);
	private:
		unsigned long _currentMillis;
		int _factorA;
		int _factorB;
		int _rA;
		int _rB;
		int _snA;
		int _snB;
};

#endif
