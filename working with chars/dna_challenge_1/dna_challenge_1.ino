char original[6] = {'c', 'a', 'g', 'g', 'g', 'a'};
char otherSide[6] = {};

int val = 0;
double totalCharsInt = 6;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 6; i++) {
    if (original[i] == 'a') {
      otherSide[i] = 't';
      val++;
    }

    if (original[i] == 't') {
      otherSide[i] = 'a';
      val++;
    }

    if (original[i] == 'c') {
      otherSide[i] = 'g';
    }

    if (original[i] == 'g') {
      otherSide[i] = 'c';
    }
  }


  for (int i = 0; i < 6; i++) {
    Serial.print(original[i]);
    Serial.print("\t");
    Serial.println(otherSide[i]);
  }

double WhoAmI = (val/totalCharsInt)*100;
  Serial.print("a+t: ");
  Serial.print(WhoAmI);
  Serial.print("%");
}


void loop() {}
