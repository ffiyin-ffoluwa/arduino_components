int sAInput = A0;
int sDInput = 2;

float analogValue;
float dvalue;
void setup() {
    pinMode(2, INPUT); 
    

  // put your setup code here, to run once
}

void loop() {
  analogValue = analogRead(sAInput);
   dvalue = analogValue * 5/1023;  //dvalue = map(analogValue, 0, 1023, 0.00, 5.00);
  int digitalValue = digitalRead(2);
  if (digitalValue == HIGH) {
    Serial.println("REACHED");
  } else {
    Serial.println("NOT REACHED");
  }

  Serial.print(dvalue);
  Serial.println("V");
  delay(1000);
  // put your main code here, to run repeatedly:
}
