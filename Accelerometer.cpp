/*
  Accelerometer.cpp - Library for accessing the accelerometer sensor in a 9DOF Stick.
  Created by Colin Harris, December 27, 2013.
*/

#include "Arduino.h"
#include "Accelerometer.h"

// Accelerometer (ADXL345)
#define ACCEL_ADDRESS (0xA6 >> 1)

// There are 6 data registers, they are sequential starting 
// with the LSB of X.  We'll read all 6 in a burst and won't
// address them individually
#define ACCEL_REGISTER_XLSB (0x32)

// Need to set power control bit to wake up the ADXL345
#define ACCEL_REGISTER_PWRCTL (0x2D)
#define ACCEL_PWRCTL_MEASURE (1 << 3)

void Accelerometer::init() {	
	_write(ACCEL_REGISTER_PWRCTL, ACCEL_PWRCTL_MEASURE);

	//Check to see if it worked!
	byte data = 0;
	_read(ACCEL_REGISTER_PWRCTL, 1, &data);  	
	if( (unsigned int)data != 8 ) {
		Serial.println("Failed to initialise the accelerometer!");
	}
}

byte Accelerometer::data_address() {
	return ACCEL_REGISTER_XLSB;
}

byte Accelerometer::i2c_address() {
	return ACCEL_ADDRESS;
}


