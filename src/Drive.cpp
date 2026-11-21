#include <Arduino.h>
#include "Constants.h"
#include "Drive.h"

namespace Drive {
    void TankDrive::SetMotor(int pwmPin, int powerPin1, int powerPin2, int speed) {
        analogWrite(pwmPin, speed);
        if (speed > 0) {
            digitalWrite(powerPin1, HIGH);
            digitalWrite(powerPin2, LOW);
        } else {    
            digitalWrite(powerPin1, LOW);
            digitalWrite(powerPin2, HIGH);
        }
    }
    void TankDrive::Drive(int leftSpeed, int rightSpeed) {
        SetMotor(DriveConstants::RIGHT_PWM_PIN, DriveConstants::RIGHT_POWER_PIN_1, DriveConstants::RIGHT_POWER_PIN_2, rightSpeed);
        SetMotor(DriveConstants::LEFT_PWM_PIN, DriveConstants::LEFT_POWER_PIN_1, DriveConstants::LEFT_POWER_PIN_2, leftSpeed);
    }
    TankDrive::TankDrive() {
        pinMode(DriveConstants::RIGHT_PWM_PIN, OUTPUT);
        pinMode(DriveConstants::RIGHT_POWER_PIN_1, OUTPUT);
        pinMode(DriveConstants::RIGHT_POWER_PIN_2, OUTPUT);

        pinMode(DriveConstants::LEFT_PWM_PIN, OUTPUT);
        pinMode(DriveConstants::LEFT_POWER_PIN_1, OUTPUT);
        pinMode(DriveConstants::LEFT_POWER_PIN_2, OUTPUT);
    }
}
