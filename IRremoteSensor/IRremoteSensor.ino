#include <IRremote.hpp>
#define SensorPin 2

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(SensorPin, ENABLE_LED_FEEDBACK);

  // put your setup code here, to run once:

}

void loop() {
  if(IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume();
  
  // put your main code here, to run repeatedly:
  }
}
