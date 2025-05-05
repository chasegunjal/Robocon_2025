//set ppr of stepper =1600(recommended) or 3200
//current <1.68 A
void stepper_arm() {
  int z = 200;  //delay



  if (ps5.Square()) {
    digitalWrite(dirPin1, HIGH);
    while (ps5.Square()) {
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(z);
    }
  }
  if (ps5.Circle()) {
    digitalWrite(dirPin1, LOW);
    while (ps5.Circle()) {
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(z);
    }
  }
}
