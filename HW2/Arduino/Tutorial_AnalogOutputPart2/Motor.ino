 const int MOTOR_PIN = 3;
 void setupMotor(){
  pinMode(MOTOR_PIN, OUTPUT);
 }
 void activateMotor(int motorPower){
  analogWrite(MOTOR_PIN, motorPower); 
  delay(2000);
 }
 void deactivateMotor(){
  analogWrite(MOTOR_PIN, 0);   
  delay(2000);
 }

