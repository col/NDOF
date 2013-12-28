/*
  Gyroscope.h - Library for accessing the gyroscope sensor in a 9DOF Stick.
  Created by Colin Harris, December 28, 2013.
*/

#ifndef Gyroscope_h
#define Gyroscope_h

#include "Arduino.h"
#include "Sensor.h"

class Gyroscope : public Sensor {

	public:
		void init();	

	protected:
		byte i2c_address();
		byte data_address();		

};

#endif