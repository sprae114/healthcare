TouchSensorDriver touch(2);
ServoDriver servo(3);
OledDisplayDriver oled;
DispenseController controller(servo, oled);

void setup() {
  touch.begin();
  servo.begin();
  oled.begin();
  oled.displayText("Touch to Move Servo");
}

void loop() {
  if (touch.read()) {
    controller.onTouchDetected();
    delay(300); // 버튼 바운싱 방지
  }
}