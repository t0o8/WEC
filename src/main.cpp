#include <Arduino.h>
#include "Constants.h"
#include "Drive.h"
#include "IRremote.h"
#include "Scoop.h"


using namespace Drive;

TankDrive tank_drive;
Scooper::Scooper scooper;
unsigned long last_signal_time = 0;
int left_motor_speed;
int right_motor_speed;
bool raised = false;

void setup() {
  
  tank_drive = TankDrive();
  IrReceiver.begin(RemoteControlConstants::RECEIVE_PIN);
  scooper.begin();
  scooper.lift_scoop();
}

void loop() {
  int drive_amount = 0;
  int turn_amount = 0;
  if (IrReceiver.decode()) {
    if ((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) == IRDATA_FLAGS_IS_REPEAT) {
      last_signal_time = millis();
    }
    if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
      
      uint16_t command = IrReceiver.decodedIRData.command;

      switch (command) {
        case ControllerConstants::FORWARD_BUTTON:
          Serial.println("Foward");
          drive_amount += DriveConstants::DRIVE_SPEED;
          break;
        case ControllerConstants::BACK_BUTTON:
        Serial.println("Back");
          drive_amount -= DriveConstants::DRIVE_SPEED;
          break;
        case ControllerConstants::LEFT_BUTTON:
          Serial.println("Left");
          turn_amount -= DriveConstants::TURN_SPEED;
          break;
        case ControllerConstants::RIGHT_BUTTON:
          Serial.println("Right");
          turn_amount += DriveConstants::TURN_SPEED;
          break;
        case ControllerConstants::LIFT_BUTTON:
          Serial.println("Lift");
          raised = true;
          break;
        case ControllerConstants::LOWER_BUTTON:
          Serial.println("Lower");
          raised = false;
          break;
        
      }
      left_motor_speed = drive_amount + turn_amount;
      right_motor_speed = drive_amount - turn_amount;
    }  
    IrReceiver.resume();
  }
  if (millis() - last_signal_time > RemoteControlConstants::TIMEOUT) {
    left_motor_speed = 0;
    right_motor_speed = 0;
  }
  tank_drive.Drive(left_motor_speed, right_motor_speed);
  if (raised) {
    scooper.lift_scoop();
  } else {
    scooper.lower_scoop();
  }
}