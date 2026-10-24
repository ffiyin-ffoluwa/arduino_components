int num = 0;
const int segDis[7] = {2,3,4,5,6,7,8};
const int led[3] = {10,11,12};
int buzzerpin = 13;
const byte digDisplay[10][7] = { {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1} //9
};
void displayDigit (int num) {
  for (int i = 0; i< 7; i++) {
    digitalWrite(segDis[i], digDisplay[num][i]);
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerpin, OUTPUT);
  for (int j = 0; j < 7; j++) {
    pinMode(segDis[j], OUTPUT);
  }
  for (int k = 0; k < 7; k++) {
    pinMode(led[k], OUTPUT);
  }
}

void loop() {
  delay(3000);
  //stop
  digitalWrite(10, HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  displayDigit(0);
  delay(2000);

  //ready
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  displayDigit(0);
  delay(3000);

  //go
  digitalWrite(10, LOW);
  digitalWrite(11,LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  for(int a = 9; a>= 0; a--){
    displayDigit(a);
      delay(1000);
  }
  } 



