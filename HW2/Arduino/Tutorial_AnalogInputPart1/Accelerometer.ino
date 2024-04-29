void setupAccelSensor() { 
  // Remove 'const' from variable declarations
  ax = X_PIN;
  ay = Y_PIN;
  az = Z_PIN;
}

void readAccelSensor() { 
  // Read analog values from pins
  ax = analogRead(X_PIN);
  ay = analogRead(Y_PIN);
  az = analogRead(Z_PIN);
}