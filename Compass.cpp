/*
  Compass.cpp - Library for accessing the compass / magnetometer sensor in a 9DOF Stick.
  Created by Colin Harris, December 27, 2013.
*/

#include "Arduino.h"
#include "Compass.h"

// Compass (HMC5883L)
#define COMPASS_ADDRESS (0x3C >> 1)

//There are 6 data registers, they are sequential starting 
//with the LSB of X.  We'll read all 6 in a burst and won't
//address them individually
#define COMPASS_REGISTER_XMSB (0x03)
#define COMPASS_REGISTER_MEASMODE (0x02)
#define COMPASS_MEASMODE_CONT (0x00)

void Compass::init() {
	_write(COMPASS_REGISTER_MEASMODE, COMPASS_MEASMODE_CONT);
	//Check to see if it worked!
	byte data = 0;
	_read(COMPASS_REGISTER_MEASMODE, 1, &data);  	
	if( (unsigned int)data != COMPASS_MEASMODE_CONT ) {
		Serial.println("Failed to initialise the compass!");
	}
}

byte Compass::i2c_address() {
  return COMPASS_ADDRESS;
}

byte Compass::data_address() {
  return COMPASS_REGISTER_XMSB;
}