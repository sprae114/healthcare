class DispenseController {
    int count;
    ServoDriver& servo;
    OledDisplayDriver& oled;
  
  public:
    DispenseController(ServoDriver& s, OledDisplayDriver& o) 
      : servo(s), oled(o), count(5) {}
  
    void onTouchDetected() {
      if (count > 0) {
        oled.displayText("남은 횟수 : " + String(count));
        servo.setAngle(-90);
        delay(10000);
        servo.setAngle(0);
        count--;
      } else {
        oled.displayText("남은 횟수가 없습니다.");
        delay(10000);
      }
    }
  };
  