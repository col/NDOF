NDOF
====

Simple Arduino library for reading the three sensors in a 9DOF stick.

Example:

```c++
#include <Wire.h>
#include <NDOF.h>

Accelerometer accel;
Compass compass;
Gyroscope gyro;

void setup() {
  Serial.begin(9600);  
  
  // Configure I2C pins with internal pull up resistors
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);

  // Initialise the sensors
  accel.init();
  compass.init();
  gyro.init();  
}

void loop() {
  // Update, read and print each sensors values
  accel.update();
  Serial.print("Accel\t");  
  print_xyz(&accel);
  
  compass.update();
  Serial.print("Compass\t");  
  print_xyz(&compass);

  gyro.update();
  Serial.print("Gyro\t");
  print_xyz(&gyro);  
  
  delay(100);  // Sample at 10Hz
}

void print_xyz(Sensor* sensor) {
  Serial.print("x: ");  
  Serial.print(sensor->x());
  Serial.print("\t\t");
  Serial.print("y: ");  
  Serial.print(sensor->y());  
  Serial.print("\t\t");  
  Serial.print("z: ");  
  Serial.println(sensor->z());  
}

```
