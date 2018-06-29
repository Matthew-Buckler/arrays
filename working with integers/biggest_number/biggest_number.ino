int data[6] = {1, 9, 5, 7, 8, 9};
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
  
  Serial.print("position of biggest value(s): ");

  bool firstTime = true;
  for (int i = 0; i < 6; i++) {
    if (biggestVal == data[i]) {
      
      if(firstTime == true){
       Serial.print(i);
       firstTime = false; 
      }
     else{
      Serial.print(", ");
      Serial.print(i);
     }
      
    }
  }
}

void loop() {}
