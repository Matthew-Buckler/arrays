#include <Keypad.h>

int password[5] = {1, 2, 3, 4, 5};

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {8, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int attempt[5] = {};
int correctAttempt[5] = {password};

int clickCount = 0;
int correctCount = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("the password is: 9, 8, 7, 6, 5");
  Serial.println("* = clear");
  Serial.println("# = attempt");
}


void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY && key != '*' && key != '#') {
    if (clickCount < 5) {
      attempt[clickCount] = key;
      clickCount++;
      //clickCount = constrain(clickCount, 0, 5);
    }
    else {
      Serial.println("greater than 5! - clearing password");
      clearData();
    }
  }

  if (key == '#') {
    check();
  }

  if (key == '*') {
    clearData();
  }
}


void check() {
  for (int i = 0; i < 6; i++) {
    if (attempt[i] - 48 == correctAttempt[i]) {
      correctCount++;
    }
  }
  if (correctCount == 5) {
    Serial.println("ACCESS GRANTED");
  }
  else {
    Serial.println("ACCESS DENIED");
  }
}


void clearData() {
  clickCount = 0;
  correctCount = 0;
  memset(attempt, 0, sizeof(attempt));
}
