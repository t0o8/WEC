#include <Arduino.h>

namespace Drive {
    class TankDrive {
        public:
            TankDrive();
            void SetMotor(int pwmPin, int powerPin1, int powerPin2, int speed);
            void Drive(int leftSpeed, int rightSpeed);
    };
}