// Define constants for gesture detection
const float G_THRESHOLD = 0.2; // Threshold for stationary gestures
const int SHAKE_THRESHOLD = 200; // Threshold for shake gesture (adjust as needed)
const int SAMPLE_RATE = 100; // Sampling rate in Hz
const int SAMPLE_INTERVAL = 1000 / SAMPLE_RATE; // Sampling interval in milliseconds

const int X_PIN = A0;
const int Y_PIN = A1;
const int Z_PIN = A2;

// Variables to store previous accelerometer readings
int prev_ax = 0;
int prev_ay = 0;
int prev_az = 0;

// Variables to store accelerometer readings
int ax = 0;
int ay = 0;
int az = 0;

// Variables to track gesture state
int currentState = -1;
int previousState = -1;

// Function to detect gestures
int detectGesture() {
  // Read accelerometer values
  readAccelSensor();
  
  // Calculate changes in acceleration along each axis
  int delta_ax = ax - prev_ax;
  int delta_ay = ay - prev_ay;
  int delta_az = az - prev_az;

  // Update previous readings for next iteration
  prev_ax = ax;
  prev_ay = ay;
  prev_az = az;

  // Calculate magnitude of acceleration vector
  float acceleration_magnitude = sqrt(sq(delta_ax) + sq(delta_ay) + sq(delta_az));

  // Detect stationary gestures
  if (abs(delta_az) < G_THRESHOLD && abs(delta_ax) < G_THRESHOLD && abs(delta_ay) < G_THRESHOLD) {
    // Determine if stationary right side up or upside down
    if (az > 0) {
      return 0; // Stationary facing up
    } else {
      return 1; // Stationary facing down
    }
  }

  // Detect fast shake gesture
  if (acceleration_magnitude > SHAKE_THRESHOLD) {
    return 2; // Shake gesture
  }

  // No gesture detected
  return -1;
}

void setup() {
  setupAccelSensor();
  setupDisplay();
  setupSampler();
  Serial.begin(9600);

}

void loop() {
  // Detect gesture
  int newGesture = detectGesture();

  // If the gesture has changed, update current state and print to serial monitor
  if (newGesture != currentState) {
    currentState = newGesture;
    // Check if the current state is different from the previous state before printing
    if (currentState != previousState) {
      switch (currentState) {
        case 0:
          Serial.println("Up"); // Stationary facing up
          break;
        case 1:
          Serial.println("Down"); // Stationary facing down
          break;
        case 2:
          Serial.println("Shaking"); // Shake gesture
          break;
        default:
          break;
      }
      // Update previous state after printing the gesture
      previousState = currentState;
    }
  }

  // If sampleSensors() returns true and Serial is available for write, print sensor readings
  if (sampleSensors() && Serial.availableForWrite()) {
    Serial.print(ax);
    Serial.print(",");
    Serial.print(ay);
    Serial.print(",");
    Serial.println(az);
  }
  
  // Delay for sampling interval
  delay(SAMPLE_INTERVAL);
}

