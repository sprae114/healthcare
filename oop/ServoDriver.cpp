#include <Servo.h>

class ServoDriver {
  Servo servo;
  int pin;
public:
  ServoDriver(int p) : pin(p) {}
  void begin() {
    servo.attach(pin);
    servo.write(0);
  }
  void setAngle(int deg) { servo.write(deg); }
};