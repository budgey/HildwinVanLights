#ifndef button_h
#define button_h

class button {
  public:
    button(int buttonPin);
    button(int buttonPin, int ledPin);
    button(int buttonPin, bool toggle = false);
    button(int buttonPin, int ledPin, bool toggle = false);

    void ledOn();
    void ledOff();
    void setDebounceTime(int debounceTime = 200);
    void loop();
    int getState();
    bool isReleased();
    bool isPressed();
    void Reset();
    int isHeld();
    int count();
    long howLong();



  private:
    int _buttonPin;
    int _ledPin;
    int debounceTime;
    unsigned long lastDebounceTime;
    unsigned long timer;
    unsigned long previousTimer;
    int counter;
    bool _toggle;
    int buttonState;
    int lastButtonState;
    bool state;
    bool _stateP;
    bool _stateR;


    unsigned long currentTime;
};

#endif
