void integrated_3(){
  if (ps5.L2()) {
    digitalWrite(Dir, HIGH);
    while (ps5.L2()) {
      int speed = ps5.L2Value();
      if (ps5.Up()) {
        digitalWrite(RELAY_1_PIN, HIGH);
        release_pwm=speed;
        SerialBT.print(">>>Release PWM:");
        SerialBT.println(release_pwm);
      } 
      else {
        digitalWrite(RELAY_1_PIN, LOW);
      }
      if (ps5.Down()) {
        digitalWrite(RELAY_2_PIN, HIGH);
      }
      else{
        digitalWrite(RELAY_2_PIN, LOW);
      }
      if (ps5.Square()) {
        digitalWrite(dirPin1, HIGH);
        // Serial.println("ARM UP");
        // SerialBT.println("ARM UP");
        while (ps5.Square()) {
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(z);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(z);
        }
      }
      if (ps5.Circle()) {
        digitalWrite(dirPin1, LOW);
        // Serial.println("ARM DOWN");
        // SerialBT.println("ARM DOWN");
        while (ps5.Circle()) {
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(z);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(z);
        }
      }
    }
  }
}