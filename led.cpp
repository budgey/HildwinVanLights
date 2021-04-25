#include "Arduino.h"
#include "led.h"

led::led(int r, int g, int b) {
  _r = r;
  _g = g;
  _b = b;
  pinMode(_r, OUTPUT);
  pinMode(_g, OUTPUT);
  pinMode(_b, OUTPUT);
};

void led::setColour(int redValue, int greenValue, int blueValue) {
  analogWrite(_r, redValue);
  analogWrite(_g, greenValue);
  analogWrite(_b, blueValue);
};

void led::setLedBrightness(int brightness) {
  analogWrite(_r, brightness);
  analogWrite(_g, brightness);
  analogWrite(_b, brightness);
};

void led::turnOff() {
  analogWrite(_r, 0);
  analogWrite(_g, 0);
  analogWrite(_b, 0);
};
