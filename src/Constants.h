#include <Arduino.h>


namespace DriveConstants {
    extern const int RIGHT_PWM_PIN;
    extern const int LEFT_PWM_PIN;

    extern const int RIGHT_POWER_PIN_1;
    extern const int RIGHT_POWER_PIN_2;

    extern const int LEFT_POWER_PIN_1;
    extern const int LEFT_POWER_PIN_2;

    extern const int DRIVE_SPEED;
    extern const int TURN_SPEED;
}
namespace RemoteControlConstants {
    extern const int RECEIVE_PIN;
    extern const unsigned long TIMEOUT;
}
namespace ControllerConstants {
    const uint16_t FORWARD_BUTTON = 67;
    const uint16_t BACK_BUTTON = 64;
    const uint16_t LEFT_BUTTON = 24;
    const uint16_t RIGHT_BUTTON = 28;
    const uint16_t LIFT_BUTTON = 94;
    const uint16_t LOWER_BUTTON = 90;
} 
namespace ScoopConstants {
    extern const int LOWERED_ANGLE;
    extern const int RAISED_ANGLE;
    extern const int PIN;
}