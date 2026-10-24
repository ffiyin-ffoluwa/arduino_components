
void setup() {
  pinMode(8, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int click = digitalRead(8);
  int xCor = analogRead(A0);
  int yCor = analogRead(A1);
  if (xCor > 510 && xCor < 500) {
    Serial.print("X: ");
    Serial.println(xCor);
  } else {
    
  }
 if (yCor > 510 && yCor < 500) {
    Serial.print("Y: ");
    Serial.println(yCor);
  } else {

  }
  /*if (click == HIGH) {
    Serial.println("Hi");
  } else {
  }*/


  // put your main code here, to run repeatedly:
}
