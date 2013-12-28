/*
  Sensor.cpp - A base class which defines the common interface for accessing a sensor.
  Created by Colin Harris, December 28, 2013.
*/

#include "Arduino.h"
#include <Wire.h>
#include "Sensor.h"

void Sensor::update() {
	byte bytes[6];
	memset(bytes,0,6);

	//read 6 bytes from the first data register
	_read(data_address(), 6, bytes);

	//now unpack the bytes
	for (int i=0;i<3;++i) {
  	_data[i] = (int)bytes[2*i] + (((int)bytes[2*i + 1]) << 8);
	}
}

int Sensor::x() {
	return (int)_data[0];
}

int Sensor::y() {
	return (int)_data[1];
}

int Sensor::z() {
	return (int)_data[2];
}

void Sensor::_write(byte reg, byte data) {	
	// Send output register address
  Wire.beginTransmission(i2c_address());
  Wire.write(reg);
  // Connect to device and send byte
  Wire.write(data); // low byte
  Wire.endTransmission();
}

void Sensor::_read(byte reg, uint8_t length, byte* output) {
	int i = 0;
	uint8_t address = i2c_address();

  // Send input register address
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();

  // Connect to device and request bytes
  Wire.beginTransmission(address);
  Wire.requestFrom(address,length);
  while(Wire.available()) { 
    // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    output[i] = c;
    i++;
  }
  Wire.endTransmission();
}