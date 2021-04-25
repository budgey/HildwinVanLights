#include <FastLED.h>
#include "button.h"
#include "led.h"
#include "pinNumbers.h"

button onButton(buttonPin1, ledPin1, true);
button modeButton(ledPin2, buttonPin2, true);
led rgbLed(redPin, greenPin, bluePin);

void setup() {
  Serial.begin(9600);
  onButton.setDebounceTime(200);
  modeButton.setDebounceTime(200);
}

void loop() {
  onButton.loop();
  modeButton.loop();
  buttonLeds();

  if (modeButton.count() == 0) {

  }

  if (modeButton.count() == 1) {

  }

  if (modeButton.count() == 2) {

  }

  if (modeButton.count() == 3) {

  }

  if (onButton.isReleased()) {
    Serial.println("Released");
  }

  if (onButton.isPressed()) {
    Serial.println("Pressed");
  }

  Serial.println(modeButton.count());
  // buttonHeldTime();
}

void buttonLeds() {
  if (onButton.getState()) {
    onButton.ledOn();
  }
  if (!onButton.getState()) {
    onButton.ledOff();
    modeButton.ledOff();
  }

  if (modeButton.count() > 0) {
    modeButton.ledOn();
  }
}

void buttonHeldTime() {
  int state = digitalRead(buttonPin1);
  if (state != buttonPrevState) {
    if (state == HIGH) {
      buttonReleased = false;
      buttonPressedAt = millis();
    }
    else {
      buttonReleased = true;
    }
    buttonPrevState = state;
  }

  if (buttonReleased == true) {
    long diff = millis() - buttonPressedAt;
    Serial.print("Button was held for: ");
    Serial.print(diff);
    Serial.println("mS");
    buttonReleased = false;
    buttonPressedAt = 0;
  }
}
