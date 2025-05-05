void shooter_1() {
  if (ps5.L2()) {
    digitalWrite(Dir, HIGH);
    while (ps5.L2()) {
      int speed = ps5.L2Value();
      analogWrite(pwm, speed);
      Serial.print("Speed:");
      Serial.println(speed);
      relay();
      stepper_arm();
      SerialBT.print("Motor PWM: ");
      SerialBT.println(speed);
      if (ps5.Up()){
        release_pwm=speed;
        SerialBT.print(">>>Release PWM:");
        SerialBT.println(release_pwm);
      }
    }
  } else {
    analogWrite(pwm, 0);
  }
}