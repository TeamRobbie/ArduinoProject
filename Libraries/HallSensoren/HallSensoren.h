/*
	HallSensoren.h - Library for driving Robbie.
	Jonas Bolle & Jorik De Bruycker
*/

#ifndef HallSensoren_h
#define HallSensoren_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class HallSensoren{
	public:
		//Constructor
		HallSensoren(int digitalPin);
		//Methodes
    void readSensors();
    void printSpeed(SoftwareSerial bt);

	private:
    int _digitalePin;
    int _status;
    int _vorigeStatus;
    int _count;
		bool _geprint;
    float _speed;
};


#endif
