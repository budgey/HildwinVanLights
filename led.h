#ifndef led_h
#define led_h

class led {
  public:
    led(int, int, int);
    void setColour(int, int, int);
    void setLedBrightness(int);
    void turnOff();
  private:
    int _r;
    int _g;
    int _b;
    int brightness;
};

#endif
