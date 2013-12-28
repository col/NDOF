/*
  Gyroscope.cpp - Library for accessing the gyroscope sensor in a 9DOF Stick.
  Created by Colin Harris, December 28, 2013.
*/

#include "Arduino.h"
#include "Gyroscope.h"

// GYRO (ITG3200)
#define GYRO_ADDRESS (0xD0 >> 1)

//There are 6 data registers, they are sequential starting 
//with the MSB of X.  We'll read all 6 in a burst and won't
//address them individually
#define GYRO_REGISTER_XMSB (0x1D)
  
// Digital Low Pass Filter
#define GYRO_REGISTER_DLPF (0x16)
#define GYRO_DLPF_FULLSCALE (0x03 << 3)
#define GYRO_DLPF_42HZ (0x03)

int GYRO_DLPF_VALUE = GYRO_DLPF_FULLSCALE | GYRO_DLPF_42HZ;

void Gyroscope::init() {
	
  _write( 
  	GYRO_REGISTER_DLPF, 
  	GYRO_DLPF_VALUE
  );

	//Check to see if it worked!
	byte data = 0;
	_read(GYRO_REGISTER_DLPF, 1, &data);  	
	if( (unsigned int)data != GYRO_DLPF_VALUE ) {
		Serial.println("Failed to initialise the compass!");
	}
}

byte Gyroscope::i2c_address() {
  return GYRO_ADDRESS;
}

byte Gyroscope::data_address() {
  return GYRO_REGISTER_XMSB;
}