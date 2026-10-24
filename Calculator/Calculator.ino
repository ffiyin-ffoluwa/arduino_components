#include <Keypad.h>

String firstNum = "";
String secondNum = "";
char symbol;
bool isPressed = false;

const byte noRows = 4;
const byte noCol = 4;

char theKeys[noRows][noCol] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};

const byte rowpins[noRows] = {8,9,10,11};
const byte colpins[noCol] = {7,6,5,4};

Keypad customKey = Keypad(makeKeymap(theKeys), rowpins, colpins, noRows, noCol);

  /*int num1 = conver(firstNum);
  int num2 = conver(secondNum);
  int result;
  
  int calculate (num1, symbol, num2) {
    if (symbol == '+') result = num1 + num2;
    if (symbol == '-') result = num1 - num2;
    if (symbol == '*') result = num1 * num2;
    if (symbol == '/') result = num1 / num2;
  }
  return(result);*/  // prints the answer

void setup() {
  Serial.begin(9600);
}

void loop() {
  char keyOne = customKey.getKey();
  
  // Keep reading until an operator is pressed
  while (keyOne != '+' && keyOne != '-' && keyOne != '*' && keyOne != '/') {
    if (keyOne) {
      firstNum += keyOne;
      Serial.println(firstNum);
    }
    keyOne = customKey.getKey();
  if (keyOne == '+' || keyOne == '-' || keyOne == '*' || keyOne == '/') {
    symbol = keyOne;
    isPressed = !isPressed;
    Serial.print(symbol);
  }
  keyOne = 0;  
  while (keyOne != '+' && keyOne != '-' && keyOne != '*' && keyOne != '/' && keyOne != '=' && keyOne != '.' && isPressed == true) {
      if (keyOne) {
        secondNum += keyOne;
        Serial.println(secondNum);
      }
      keyOne = customKey.getKey();
  }
  }


}