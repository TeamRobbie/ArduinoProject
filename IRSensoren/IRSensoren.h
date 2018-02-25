/*
	IRSensoren.h - Library for driving Robbie.
	Jonas Bolle & Jorik De Bruycker
*/

#ifndef IRSensoren_h
#define IRSensoren_h

#include "Arduino.h"

class IRSensoren{
	public:
    IRSensoren(int s0, int s1, int s2, int analogIn);
    int * readSensors();
	private:
    int _s0;
  	int _s1;
  	int _s2;
  	int _analogIn;
    static int _waardes[8];

};


#endif
