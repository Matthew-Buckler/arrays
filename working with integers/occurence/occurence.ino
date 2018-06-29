int original[30] {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7};
int store[10] = {};
int val = 0;

void setup() {
  Serial.begin(9600);

  for (int x = 0; x < 30; x++) {
    val = original[x];
    store[val] += 1;
    val = 0; //resets to 0 each time
  }

  for (int i = 0; i < 10; i++) {
    Serial.print("times ");
    Serial.print(i);
    Serial.print(" occured: ");
    Serial.println(store[i]);
  }
}


void loop() {}
