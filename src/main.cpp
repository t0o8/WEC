#include <Arduino.h>
#include "Constants.h"
#include "Drive.h"

using namespace Drive;
int myFunction(int, int);


TankDrive tank_drive;

void setup() {
  tank_drive = TankDrive();
}

void loop() {
  tank_drive.Drive(100, 100);
}