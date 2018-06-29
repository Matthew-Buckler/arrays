char original[6] = {'a', 't', 'c', 'g', 'g', 'a'};
char otherSide[6] = {};


void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 6; i++) {
    if (original[i] == 'a') {
      otherSide[i] = 't';
    }

    if (original[i] == 't') {
      otherSide[i] = 'a';
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
}


void loop() {}
