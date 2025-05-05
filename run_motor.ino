void run_motor(int condn, int z) {
  switch (condn) {
    case 1:  //left

      digitalWrite(dirB, LOW);
      analogWrite(pwmB, z);
      digitalWrite(dirRF, HIGH);
      analogWrite(pwmRF, z / 2); //1.8 initial value
      digitalWrite(dirLF, HIGH);
      analogWrite(pwmLF, z / 2);
      break;

    case 2:  // right
      digitalWrite(dirB, HIGH);
      analogWrite(pwmB, z);
      digitalWrite(dirLF, LOW);
      analogWrite(pwmLF, z / 2);
      digitalWrite(dirRF, LOW);
      analogWrite(pwmRF, z / 2);
      break;

    case 3:  //clockwise
      digitalWrite(dirLF, HIGH);
      analogWrite(pwmLF, z);
      digitalWrite(dirRF, HIGH);
      analogWrite(pwmRF, z);
      digitalWrite(dirB, HIGH);
      analogWrite(pwmB, z);
      break;

    case 4:  //anticlockwise

      digitalWrite(dirB, LOW);
      analogWrite(pwmB, z);
      digitalWrite(dirLF, LOW);
      analogWrite(pwmLF, z);
      digitalWrite(dirRF, LOW);
      analogWrite(pwmRF, z);
      break;

    case 5:  //stop1
      analogWrite(pwmLF, z);
      analogWrite(pwmRF, z);
      analogWrite(pwmB, z);
      break;

    case 6:  //stop2
      analogWrite(pwmLF, z);
      analogWrite(pwmRF, z);
      analogWrite(pwmB, z);
      break;

    case 7:  //front
      digitalWrite(dirLF, HIGH);
      analogWrite(pwmLF, z);
      digitalWrite(dirRF, LOW);
      analogWrite(pwmRF, z);
      analogWrite(pwmB, 0);
      break;

    case 8:  //back
      digitalWrite(dirLF, LOW);
      analogWrite(pwmLF, z);
      digitalWrite(dirRF, HIGH);
      analogWrite(pwmRF, z);
      analogWrite(pwmB, 0);
      break;
  }
}
