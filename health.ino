#include <Servo.h> //  서보 모터 제어 라이브러리
#include <Wire.h> // I2C 통신용 기본 라이브러리
#include <Adafruit_GFX.h> // Adafruit에서 만든 그래픽 기본 라이브러리
#include <Adafruit_SSD1306.h> //  OLED 디스플레이(128x64 등)용 전용 라이브러리

// 핀 설정
const int touchPin = 2;     // TTP223B 터치센서
const int servoPin = 3;     // 서보모터 제어 핀

// OLED 설정
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// 서보 객체 및 남은 횟수
Servo myServo;
int count = 5;

void setup() {
  pinMode(touchPin, INPUT);               // 터치센서 핀은 입력으로 설정
  myServo.attach(servoPin);               // 서보모터 핀 제어 연결
  myServo.write(0);                       // 서보 초기 각도 설정

  // OLED 디스플레이 초기화
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);                         // 디스플레이 초기화 실패시 멈춤
  }

  display.clearDisplay();                 // 화면 지우기
  display.setTextSize(1);                 // 글자 크기 설정
  display.setTextColor(SSD1306_WHITE);    // 글자 색상 (흰색)
  display.setCursor(0,0);                 // 시작 위치 좌표 (왼쪽 위)
  display.println("Touch to Move Servo"); // 텍스트 출력
  display.display();                      // 실제 화면에 표시
}


void loop() {
  int touchState = digitalRead(touchPin);

  if (touchState == HIGH) {
    display.clearDisplay();
    display.setCursor(0, 0);

    if (count > 0) {
      myServo.write(90); // -90도 위치 (서보 모터에 따라 0~180 범위일 수 있음)
      display.printf("남은 횟수 : %d", count);
      display.display();
      delay(10000); // 10초 유지

      myServo.write(0); // 원위치
      count--;
    } else {
      display.println("남은 횟수가 없습니다.");
      display.display();
      delay(10000); // 10초 유지
    }

    // 터치 중복 방지
    while (digitalRead(touchPin) == HIGH) {
      delay(10);
    }

    // 대기 화면 복귀
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Touch to Move Servo");
    display.display();
  }

  delay(100);
}
