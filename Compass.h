/*
  Compass.h - Library for accessing the compass / magnetometer sensor in a 9DOF Stick.
  Created by Colin Harris, December 27, 2013.
*/

#ifndef Compass_h
#define Compass_h

#include "Arduino.h"
#include "Sensor.h"
  
class Compass : public Sensor {

	public:
		virtual void init();

	protected:
		byte i2c_address();
		byte data_address();		

};

#endif