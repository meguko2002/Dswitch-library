/*  When buttonPin turns HIGH into LOW,"DeboucedSwitch.state()" returns HIGH only once in an interval 
 *  even if  buttonPin turns LOW and HIGH several times.
 *  DeboucedSwitch.call() returns buttonPin state. */

#include <Dswitch.h>

#define buttonPin  2
#define ledPin  14 

Dswitch sw(buttonPin);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);           
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  const long interval = 100;
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(ledPin, sw.state());   //blink LED for only 100msec(interval)
    Serial.println(sw.call());
  }
}

