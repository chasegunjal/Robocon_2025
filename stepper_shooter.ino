//keep ppr = 400
void stepper_shooter() {
  int z = 500;  // Initial delay (will get updated based on joystick)

  // Read joystick position and map to delay (speed)
  uint8_t r2 = ps5.R2Value(); //datatype changed if doesnt work stick to int
  z = map(r2, 0, 255, 200, 1000);  // Map stick to delay range (lower = faster)
  z = constrain(z, 200, 1000);     // Just in case

  if (ps5.Triangle()) {
    digitalWrite(dirPin2, HIGH);  // One direction
    while (ps5.Triangle()) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(z);
    }
  }

  if (ps5.Cross()) {
    digitalWrite(dirPin2, LOW);     // Opposite direction
    while (ps5.Cross()) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(z);
    }
  }
}
// keep ppr = 400
// const int ppr = 1600;
// int stepCount = 0; // Global variable to track steps

// void stepper_shooter() {
//   int z = 500;  // Initial delay (will get updated based on joystick)

//   // Read joystick position and map to delay (speed)
//   uint8_t r2 = ps5.R2Value(); // datatype changed if doesn't work, stick to int
//   z = map(r2, 0, 255, 200, 1000);  // Map stick to delay range (lower = faster)
//   z = constrain(z, 200, 1000);     // Just in case

//   if (ps5.Triangle()) {
//     digitalWrite(dirPin2, HIGH);  // One direction
//     while (ps5.Triangle()) {
//       for(int i = 0; i < 400; i++){
//         digitalWrite(stepPin2, HIGH);
//         delayMicroseconds(z);
//         digitalWrite(stepPin2, LOW);
//         delayMicroseconds(z);

//         stepCount++;  // Increase step count
//         float angle = (360.0 * stepCount) / ppr;
//         Serial.print("Angle: ");
//         Serial.println(angle);
//         Serial.println(i);
//       }
      
//     }
//   }

//   if (ps5.Cross()) {
//     digitalWrite(dirPin2, LOW);  // Opposite direction
//     while (ps5.Cross()) {
//       for(int i = 0; i < 400; i++){
//         digitalWrite(stepPin2, HIGH);
//         delayMicroseconds(z);
//         digitalWrite(stepPin2, LOW);
//         delayMicroseconds(z);

//         stepCount--;  // Decrease step count (reverse)
//         float angle = (360.0 * stepCount) / ppr;
//         Serial.print("Angle: ");
//         Serial.println(angle);
//         Serial.println(i);
//       }
//     }
//   }
// }
