int sampleTime = 0; // Time of last sample (in Sampling tab)
// Acceleration values recorded from the readAccelSensor() function

int sampleRate = 50;                  // Sensor reading Frequency (Hz)
unsigned long sampleDelay = 1e6/sampleRate; //Time(μs) between samples
unsigned long timeStart = 0;              //Start time timing variable
unsigned long timeEnd = 0;                  //End time timing variable

void setupSampler() {
  setupAccelSensor();
  setupDisplay();
  Serial.begin(9600);
}

bool sampleSensors(){
  timeEnd = micros();
  if(timeEnd - timeStart >= sampleDelay) {
    displaySampleRate(timeEnd);
    timeStart = timeEnd;

    // Read the sensors and store their outputs in global variables
    sampleTime = millis();
    readAccelSensor();     // values stored in "ax", "ay", and "az"
    return true;
  }
  return false;
}

void displaySampleRate(unsigned long currentTime) {
     int nSamples = 100;
     static int count = 0;
     static unsigned long lastTime = 0;

     count++;
     if(count == nSamples) {
     double avgRate = nSamples * 1e6 / (currentTime - lastTime);
     String message = String(avgRate) + " Hz";
     writeDisplay(message.c_str(), 3, false);

     // reset
    count = 0;
    lastTime = currentTime;
    }
}

void loopSerial() {
     // Note: we only print values when we have a new sample!!!
     // Also note that we added the second argument to the conditional to    
     // check if there is space in the buffer, otherwise it will stall when 
     // the buffer is full. Credit to Kyle for discovering the solution!
     if(sampleSensors() && Serial.availableForWrite()) {
          Serial.print(ax);
          Serial.print(",");
          Serial.print(ay);
          Serial.print(",");
          Serial.println(az);
     }
}
