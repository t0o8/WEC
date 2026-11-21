#include "Scoop.h"
#include "Constants.h"
#include <Servo.h>

namespace Scooper {
    Servo servo;
    Scooper::Scooper() {
        servo.attach(ScoopConstants::PIN);
    }
    void Scooper::begin() {
        servo.attach(ScoopConstants::PIN);
    }
    void Scooper::lift_scoop() {
        servo.write(ScoopConstants::RAISED_ANGLE);
    }
    void Scooper::lower_scoop() {
        servo.write(ScoopConstants::LOWERED_ANGLE);
    }
}