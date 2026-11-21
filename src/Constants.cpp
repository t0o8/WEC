#include "Constants.h"

namespace DriveConstants {
    const int RIGHT_PWM_PIN = 5;
    const int LEFT_PWM_PIN = 6;

    const int RIGHT_POWER_PIN_1 = 2;
    const int RIGHT_POWER_PIN_2 = 4;
    
    const int LEFT_POWER_PIN_1 = 7;
    const int LEFT_POWER_PIN_2 = 8;

    const int DRIVE_SPEED = 100;
    const int TURN_SPEED = 100;
}
namespace RemoteControlConstants {
    const int RECEIVE_PIN = 11;
    const unsigned long TIMEOUT = 250;z
}
namespace ScoopConstants {
    const int LOWERED_ANGLE = 10;
    const int RAISED_ANGLE = 60;
    const int PIN = 9;
}