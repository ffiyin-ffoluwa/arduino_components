#include <Keypad.h>

const byte rowsize = 4;
const byte colsize = 4;
const byte rowpin[rowsize] = {8,9,10,11};
const byte colpin[rowsize] = {7,6,5,4};
char keypadarr[rowsize][colsize] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9','0', 'C', 'B'},
  {'A', 'D', 'E', 'F'}
};
Keypad mykey = Keypad(makeKeymap(keypadarr), rowpin, colpin, rowsize, colsize);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  char getkey1 = mykey.getKey();
  if(getkey1) {
    Serial.println(getkey1);
  }
  // put your main code here, to run repeatedly:

}
