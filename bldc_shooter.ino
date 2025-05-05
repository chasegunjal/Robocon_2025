/*void shooter_bldc() {

  if (ps5.L2()){
    digitalWrite(Dir , HIGH);
    while(ps5.L2()){
      int speed = ps5.L2Value();
      analogWrite(pwm,speed);
    }
  }
  else{
    analogWrite(pwm, 0);
  }

}*/

void shooter_bldc() {
  static int currentspeed = 0; // make it static so it remembers last speed
  int speed = 0;

  if (ps5.L2()) {
    digitalWrite(Dir, HIGH);
    
    speed = ps5.L2Value();

    if (speed > currentspeed) {
      currentspeed += 3; // Ramp up
      if (currentspeed > speed) currentspeed = speed; // No overshoot
    } 
    else if (speed < currentspeed) {
      currentspeed -= 3; // Ramp down
      if (currentspeed < speed) currentspeed = speed; // No overshoot
    }

    analogWrite(pwm, currentspeed);
    Serial.println(currentspeed);
  } 
  else {
    // When button released, decrease speed slowly
    if (currentspeed > 0) {
      currentspeed -= 3; // Gradually reduce
      if (currentspeed < 0) currentspeed = 0;
      analogWrite(pwm, currentspeed);
      Serial.println(currentspeed);
    }
    else {
      analogWrite(pwm, 0);
    }
  }

  delay(30); // smooth oper




}

/*unsigned long previousMillis = 0;
const unsigned long interval = 10; // Update every 10ms

int currentspeed = 0; // The speed we are actually giving to motor
int targetspeed = 0;  // The desired speed (based on L2)

void shooter_bldc() {
  unsigned long currentMillis = millis();

  // Set the target speed
  if (ps5.L2()) {
    digitalWrite(Dir, HIGH);
    targetspeed = ps5.L2Value(); // Set according to trigger pressure
  } else {
    targetspeed = 0; // No trigger -> target 0
  }

  // Every interval milliseconds, adjust current speed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (currentspeed < targetspeed) {
      currentspeed += 2; // Small ramp up
      if (currentspeed > targetspeed) currentspeed = targetspeed; // Don't overshoot
    } 
    else if (currentspeed > targetspeed) {
      currentspeed -= 2; // Small ramp down
      if (currentspeed < targetspeed) currentspeed = targetspeed;
    }

    analogWrite(pwm, currentspeed); // Apply PWM
    Serial.println(currentspeed);
  }
}*/


/*void shooter_bldc() {

  int currentspeed = 0;
  int speed = 0;

  if (ps5.L2()){
    digitalWrite(Dir , HIGH);
    while(ps5.L2()){
       speed = ps5.L2Value();
      if (speed > currentspeed ){
        speed += 5;
        currentspeed = speed;
      }
      else if ( speed < currentspeed){
        speed -= 5;
        currentspeed = speed;
      }
      analogWrite(pwm,speed);
      Serial.println(speed);
      delay(20);
    }
  }
  else{
    
    analogWrite(pwm, 0);
    Serial.println(speed);
  }

}*/

/*void shooter_bldc() {
  static int currentSpeed = 0; // Store current speed between calls
  int targetSpeed = 0;
  Serial.println(currentSpeed);

  if (ps5.L2()) {
    digitalWrite(Dir, HIGH);
    targetSpeed = ps5.L2Value();

    // Ramp up or down toward target speed
    while (ps5.L2()) {
      targetSpeed = ps5.L2Value(); // Continuously update target
      if (currentSpeed < targetSpeed) {
        currentSpeed++;
        analogWrite(pwm, currentSpeed);
      } else if (currentSpeed > targetSpeed) {
        currentSpeed--;
        analogWrite(pwm, currentSpeed);
      }

     // analogWrite(pwm, currentSpeed);
      delay(5); // Smoothing delay (adjust for faster/slower ramp)
    }
  }

  // Ramp down smoothly to zero
  while (currentSpeed > 0) {
    currentSpeed--;
    analogWrite(pwm, currentSpeed);
    delay(5);
  }

  analogWrite(pwm, 0);
}*/

/*int currentSpeed = 0;
int targetSpeed = 0;

void shooter_bldc() {
  if (ps5.L2()) {
    digitalWrite(Dir, HIGH);
    targetSpeed = ps5.L2Value();  // Read trigger pressure as target speed
  } else {
    targetSpeed = 0;  // If not pressed, target is zero
  }

  // Smoothly adjust current speed toward target
  if (currentSpeed < targetSpeed) {
    currentSpeed++;
  } else if (currentSpeed > targetSpeed) {
    currentSpeed--;
  }

  analogWrite(pwm, currentSpeed);
  delay(5);  // Small delay for smooth transition (optional, or use millis timing)
}*/

