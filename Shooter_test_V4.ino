void v4_shooter() {
  if (ps5.L1()) {
    lastPWM = pwmValues[currentStep]; // Save last PWM before stopping
    analogWrite(pwm, 0); // Stop the motor
    isStopped = true;
    Serial.println("Motor Stopped. Press R1 to resume last PWM value.");
    SerialBT.println("Motor Stopped. Press R1 to resume last PWM value.");
  } 
  else if (ps5.R1() && isStopped) { // Resume last PWM value
    analogWrite(pwm, lastPWM);
    isStopped = false;
    Serial.print("Motor Resumed at PWM: ");
    Serial.println(lastPWM);
    SerialBT.print("Motor Resumed at PWM: ");
    SerialBT.println(lastPWM);
  } 
  if (!isStopped) {
    if (ps5.R2() && currentStep < 7) { // Step up PWM
      currentStep++;
      analogWrite(pwm, pwmValues[currentStep]);
      Serial.print("PWM increased to: ");
      Serial.println(pwmValues[currentStep]);
      SerialBT.print("PWM increased to: ");
      SerialBT.println(pwmValues[currentStep]);
      delay(200); // Debounce delay
    } 
    else if (ps5.L2() && currentStep > 0) { // Step down PWM
      currentStep--;
      analogWrite(pwm, pwmValues[currentStep]);
      Serial.print("PWM decreased to: ");
      Serial.println(pwmValues[currentStep]);
      SerialBT.print("PWM decreased to: ");
      SerialBT.println(pwmValues[currentStep]);
      delay(200); // Debounce delay
    }
  }
  if (ps5.Up()) {
        digitalWrite(RELAY_1_PIN, HIGH);
        release_pwm=pwmValues[currentStep];
        SerialBT.print(">>>Release PWM:");
        SerialBT.println(release_pwm);
        SerialBT.println("Jaw Open");
        Serial.print(">>>Release PWM:");
        Serial.println(release_pwm);
        Serial.println("Jaw Open");
      } 
  else {
    digitalWrite(RELAY_1_PIN, LOW);
  }
  if (ps5.Down()) {
    digitalWrite(RELAY_2_PIN, HIGH);
    SerialBT.println("Jaw Close");
    Serial.println("Jaw Close");
  }
  else{
    digitalWrite(RELAY_2_PIN, LOW);
  }
  if (ps5.Square()) {
    digitalWrite(dirPin1, HIGH);  
    while (ps5.Square()) {
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(z);
      Serial.println("ARM UP");
      SerialBT.println("ARM UP");
    }
  }
  if (ps5.Circle()) {
    digitalWrite(dirPin1, LOW);
    while (ps5.Circle()) {
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(z);
      Serial.println("ARM DOWN");
      SerialBT.println("ARM DOWN");
    }
  }

}
