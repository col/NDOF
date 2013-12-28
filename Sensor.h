/*
  Sensor.h - A base class which defines the common interface for accessing a sensor.
  Created by Colin Harris, December 28, 2013.
*/

#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor {

	public:
		virtual void init();
		virtual void update();
		int x();
		int y();
		int z();

	protected:
		int _data[3];
		virtual inline byte i2c_address();
		virtual inline byte data_address();
		void _write(byte reg, byte data);
		void _read(byte reg, uint8_t length, byte* output);

};

#endif