class TouchSensorDriver {
    int pin;
  public:
    TouchSensorDriver(int p) : pin(p) {}
    void begin() { pinMode(pin, INPUT); }
    bool read() { return digitalRead(pin) == HIGH; }
  };
  