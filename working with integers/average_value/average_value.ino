int original[30] {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7};

int Sum = 0;

double IntsInArr = 30;


void setup() {
  Serial.begin(9600);

  for (int x = 0; x < 30; x++) {
    Sum = Sum + original[x];
  }

  Serial.print("Average value (as a decimal): ");
  Serial.print(Sum / IntsInArr);
}


void loop() {}
