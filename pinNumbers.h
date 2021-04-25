//on off button pins
int ledPin1 = 2;
int buttonPin1 = 3;

//mode button pins
int ledPin2 = 4;
int buttonPin2 = 5;

int ledStripPin = 7;

//rgb led pins
int redPin = 10;
int greenPin = 11;
int bluePin = 12;

bool buttonReleased = false;
byte buttonPrevState = 0;
unsigned long buttonPressedAt = 0;
