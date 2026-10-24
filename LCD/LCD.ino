#include <LiquidCrystal.h>
// yhe led cong LiquidCrystal lcd(RS, E,D4,D5,D6,D7)
LiquidCrystal lcd(12, 11, 5 ,4,3,2);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  }
  // put your setup code here, to run once:

void loop() {
  lcd.print("Hi");
  lcd.setCursor(0,1);
  lcd.print("Hi");
  lcd.print(millis()/1000);
  }
  // put your main code here, to run repeatedly:


