void setup() {
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
		char incoming_data = Serial.read();
    Serial.print(incoming_data);
	}
}
