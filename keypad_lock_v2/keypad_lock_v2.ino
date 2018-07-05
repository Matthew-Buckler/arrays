#include <Keypad.h>

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
int correctAttempt[5] = {5, 5, 5, 5, 5};

int clickCount = 0;
int correctCount = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("keypad lock v2");
  Serial.println("command list:");
  Serial.println("- * = change password");
  Serial.println("- # = attempt");
  Serial.println("the firewall password is: 5,5,5,5,5");
}


bool rob = true;
void loop() {
  char key = keypad.getKey();


  if (key == '*') {
    if (rob == true) {//we will get robbed! ah!
      Serial.println("enter the correct password before changing");
    }
    else {
      Serial.println("password changed");
      Serial.println("your new password is:");

      for (int i = 0; i < 5; i++) {

        correctAttempt[i] = attempt[i];

        Serial.println(correctAttempt[i]);
      }
    }
  }


  if (key != NO_KEY && key != '*' && key != '#') {
    attempt[clickCount] = key - 48;
    clickCount++;
  }


  if (key == '#') {
    check();
    clearData();
  }
}


void check() {
  for (int i = 0; i < 5; i++) {
    if (attempt[i] == correctAttempt[i]) {
      correctCount++;
    }
  }
  if (correctCount == 5) {
    Serial.println("ACCESS GRANTED");
    rob = false;
  }
  else {
    Serial.println("ACCESS DENIED");
    rob = true;
  }
}


void clearData() {
  clickCount = 0;
  correctCount = 0;
  memset(attempt, 0, sizeof(attempt));
}
