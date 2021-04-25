#include "Arduino.h"
#include "button.h"

//constructor for buttons with no leds
button::button(int buttonPin) {
  _buttonPin = buttonPin;
  pinMode(_buttonPin, INPUT);
};

//constructor for buttons with leds
button::button(int buttonPin, int ledPin) {
  _buttonPin = buttonPin;
  _ledPin = ledPin;
  pinMode(_buttonPin, INPUT);
  pinMode(_ledPin, OUTPUT);
};

//constructor for momentary buttons with leds to be togglable.
button::button(int buttonPin, int ledPin, bool toggle) {
  _buttonPin = buttonPin;
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT);
  pinMode(_buttonPin, INPUT);
  _toggle = toggle;
};

//constructor for momentary buttons to be togglable.
button::button(int buttonPin, bool toggle) {
  _buttonPin = buttonPin;
  pinMode(_buttonPin, INPUT);
  _toggle = toggle;
};

void button::ledOn() {
  digitalWrite(_ledPin, HIGH);
};

void button::ledOff() {
  digitalWrite(_ledPin, LOW);
};

void button::setDebounceTime(int time) {
  debounceTime = time;
};

void button::loop() {
  int currentState = digitalRead(_buttonPin);
  unsigned long currentTime = millis();

  if (_toggle) {
    if (currentState != lastButtonState) {
      lastDebounceTime = millis();
    }

    if ((currentTime - lastDebounceTime) > debounceTime) {
      if (currentState != buttonState) {
        buttonState = currentState;
        if (buttonState == HIGH) {
          state = !state;
          counter++;
          if (counter > 3) {
            counter = 0;
          }
        }
      }
    }
    lastButtonState = currentState;
  }

  if (!_toggle) {
    if ((currentTime - lastDebounceTime) > debounceTime) {
      lastDebounceTime = millis();
      state = currentState;
    }
  }
};

int button::getState() {
  return state;
};

//method for toggle when the button is pressed
bool button::isPressed() {
  bool reading = digitalRead(_buttonPin);
  if (reading != _stateP) {
    _stateP = reading;
    if (_stateP) {
      return true;
    }
  }
  return false;
};

//method for toggle when the button is released.
bool button::isReleased() {
  bool reading = digitalRead(_buttonPin);
  if (reading != _stateR) {
    _stateR = reading;
    if (!_stateR) {
      return true;
    }
  }
  return false\\\;
};

long button::howLong() {
  int pinState = digitalRead(_buttonPin);
  if (pinState == HIGH) {
    currentTime = millis();
  }
  return currentTime;
}



//method to reset the count and turn led off
void button::Reset() {
  //count = 0;
  // digitalWrite(_ledPin, LOW);
};

int button::isHeld() {
  int pinState = digitalRead(_buttonPin);
  if (pinState == HIGH)
    return true;
  else
    return false;
};








//method for counting how many times the button has been pressed.
//paramter to set max count limimt
int button::count() {
  return counter;
};
