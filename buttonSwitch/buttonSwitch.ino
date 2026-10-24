int ledpin = 1;
int buttonpin = 2;
/*bool ledstate = LOW;
bool buttonstate = false;*/

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int buttonread = digitalRead(buttonpin);
  if (buttonread == HIGH) {
    digitalWrite(ledpin, HIGH);
    delay(4000);
    digitalWrite(3, HIGH);
    
  } else {
    digitalWrite(ledpin, LOW);
    delay(2000);
    digitalWrite(3, LOW);
  }
  /*if(buttonread == HIGH && !buttonstate) {
    buttonstate = true;
    ledstate = !ledstate;
    digitalWrite(ledpin, ledstate);
  }
  if (buttonread == LOW) {
    buttonstate = false;
  }*/
  // put your main code here, to run repeatedly:

}