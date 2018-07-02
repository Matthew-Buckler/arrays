char original[6] = {'c', 'a', 'g', 'g', 'g', 'a'};

int aCount = 0;
int tCount = 0;
int cCount = 0;
int gCount = 0;



void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 6; i++) {
    if (original[i] == 'a') {
      aCount++;
    }

    if (original[i] == 't') {
      tCount++;
    }

    if (original[i] == 'c') {
      cCount++;
    }

    if (original[i] == 'g') {
      gCount++;
    }
  }

  Serial.print("a: ");
  Serial.println(aCount);
  Serial.print("t: ");
  Serial.println(tCount);
  Serial.print("c: ");
  Serial.println(cCount);
  Serial.print("g: ");
  Serial.println(gCount);

  int arr[4] = {aCount, tCount, cCount, gCount};
  int biggestNumber = 0;
  
    for (int i = 0; i < 4; i++) {
     if (arr[i] > biggestNumber) {
      biggestNumber = arr[i]; 
    }
  }
  Serial.println(biggestNumber);
}


void loop() {}
