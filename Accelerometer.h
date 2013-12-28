/*
  Accelerometer.h - Library for accessing the accelerometer sensor in a 9DOF Stick.
  Created by Colin Harris, December 27, 2013.
*/

#ifndef Accelerometer_h
#define Accelerometer_h

#include "Sensor.h"

class Accelerometer : public Sensor {

	public:
		void init();		

	protected:
		byte i2c_address();
		byte data_address();

};

#endif