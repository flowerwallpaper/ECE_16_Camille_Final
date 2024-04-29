int PWM_pin = 3; // define PWM_pin as an integer variable and assign pin 3

void setup() {
    pinMode(PWM_pin, OUTPUT); // set the PWM pin as an output
}

void loop() {
    analogWrite(PWM_pin, 0);   // turn on the LED at minimum brightness
    delay(2000);
    analogWrite(PWM_pin, 127); // turn on the LED at half brightness
    delay(2000);
    analogWrite(PWM_pin, 255); // turn on the LED at maximum brightness
    delay(2000);
    analogWrite(PWM_pin, 90);  // turn on the LED at 90/255 brightness
    delay(2000);
}
