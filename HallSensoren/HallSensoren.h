/*
	HallSensoren.h - Library for driving Robbie.
	Jonas Bolle & Jorik De Bruycker
*/

#ifndef HallSensoren_h
#define HallSensoren_h

#include "Arduino.h"

class HallSensoren{
	public:
		//Constructor
		HallSensoren(int digitalPin);
		//Methodes
    void readSensors();
    void calculateSpeed();

	private:
    int _digitalePin;
    int _status;
    int _vorigeStatus;
    int _count;
    float _speed;
};


#endif
