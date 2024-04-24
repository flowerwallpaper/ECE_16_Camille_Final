const int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;

unsigned long previousMillisCounter = 0;
unsigned long previousMillisPrint = 0;
unsigned long intervalCounter = 1000; // 1 second
unsigned long intervalPrint = 100; // 100 milliseconds
unsigned long counter = 0;

bool stopwatchRunning = false;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      toggleStopwatch();
    }
    lastButtonState = buttonState;
  }
  if (stopwatchRunning) {
    unsigned long currentMillisCounter = millis();
    if (currentMillisCounter - previousMillisCounter >= intervalCounter) {
      counter++;
      previousMillisCounter = currentMillisCounter;
    }
    unsigned long currentMillisPrint = millis();
    if (currentMillisPrint - previousMillisPrint >= intervalPrint) {
      Serial.println(counter);
      previousMillisPrint = currentMillisPrint;
    }
  }
}

void toggleStopwatch() {
  stopwatchRunning = !stopwatchRunning;
  if (stopwatchRunning) {
    previousMillisCounter = millis();
    previousMillisPrint = millis();
  }
}
