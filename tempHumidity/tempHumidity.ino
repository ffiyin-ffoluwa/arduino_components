float s = 0.01; 
int raw;
float V;
float T;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  raw = analogRead(A2);
  V = raw  * (5.00/ 1023);
  T = (raw * 0.125)- 22.0;
  Serial.print(raw); Serial.print(" ");
  Serial.print(V); Serial.print(" ");
  Serial.print(T); Serial.println(" ");
  delay(2000);
  // put your main code here, to run repeatedly:

}
