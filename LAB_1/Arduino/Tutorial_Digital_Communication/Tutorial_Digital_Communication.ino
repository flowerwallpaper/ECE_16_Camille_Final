const int LED_PIN = 5; // map LED_PIN to the GPIO pin to drive the LED = D5
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // turn the LED on
      delay(500); //wait for half a second
      digitalWrite(LED_PIN, LOW); // turn the LED off
      delay(1000); //wait for a second
}
