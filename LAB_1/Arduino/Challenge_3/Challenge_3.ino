#include <Arduino.h>

const int buttonPin = 2; 
unsigned long previousMillis = 0;
const long interval = 1000;
int timer = 0;
bool countingDown = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();
  if (digitalRead(buttonPin) == LOW) {
    timer++;
    countingDown = false;
    previousMillis = currentMillis;
    delay(50); 
  } else {
    if (currentMillis - previousMillis >= 3000 && !countingDown) {
      countingDown = true;
      previousMillis = currentMillis;
    }

    if (countingDown && currentMillis - previousMillis >= interval) {
      if (timer > 0) {
        timer--;
      }
      previousMillis = currentMillis;
    }
  }
  Serial.println(timer);
  delay(100);
}
