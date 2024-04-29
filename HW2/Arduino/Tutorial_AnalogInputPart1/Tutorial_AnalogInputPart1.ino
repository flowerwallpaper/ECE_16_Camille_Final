int ax = 0; 
int ay = 0;
int az = 0;

const int X_PIN = A0;
const int Y_PIN = A1;
const int Z_PIN = A2;

void setup() {
  Serial.begin(9600);
  setupAccelSensor();
  pinMode(X_PIN, INPUT); 
  pinMode(Y_PIN, INPUT);
  pinMode(Z_PIN, INPUT);
}

void loop() {
  readAccelSensor(); 

  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.println(az);

  delay(50);
}