int data[6] = {1, 9, 5, 7, 8, 6};
int biggestVal = 0;
int biggestPosition = 0;


void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 6; i++) {
    if (data[i] > biggestVal) {
      biggestVal = data[i];
      biggestPosition = i;
    }
  }
  Serial.print("biggest value: ");
  Serial.println(biggestVal);
  Serial.print("biggest position: ");
  Serial.println(biggestPosition);
}

void loop() {}
