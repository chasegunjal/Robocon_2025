#include <BluetoothSerial.h>

#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>
#include <esp_system.h>


//relay pin defination:
const int RELAY_1_PIN = 12;  // for pressurizing piston
const int RELAY_2_PIN = 13;  // for depressurizing  //try writing #define if error

//arm stepper pin defination:

const int stepPin1 = 25;
const int dirPin1 = 26;

//shooter stepper pin defination:

const int stepPin2 = 27;
const int dirPin2 = 14;

//drive pins:

const int pwmLF = 16, pwmRF = 23, pwmB = 18;
const int dirLF = 4, dirRF = 19, dirB = 17;

// constants for drive:
float Lx, Rx, Ly, Ry, z;  //used datatype cording to ps5 library , if error occured stick to float
float control;

//shooter motor pins:

const int pwm = 21, Dir = 22; //for r2 make pwm = 21 and dir = 22

// serial bt feedback
BluetoothSerial SerialBT;
int release_pwm=0;

int pwmValues[8] = {50, 85, 120, 155, 190, 225, 240, 255}; // 8 step values
int currentStep = 0; // Track the current step index
int lastPWM = 0; // Stores last PWM value before stopping
bool isStopped = 1; // Start with motor stopped

void setup() {

  Serial.begin(115200);
  ps5.begin("88:03:4C:93:FE:13");
  //ps5.begin("BC:C7:46:0A:66:DA");
// Bluetooth serial terminal
  SerialBT.begin("ESP32-Bot1 ");    // Bluetooth Device Name
  Serial.println("Bluetooth Started! Ready to pair...");

  //relay pins pinmode:

  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);

  //initializing relay pins

  digitalWrite(RELAY_1_PIN, LOW);  // OFF initially
  digitalWrite(RELAY_2_PIN, LOW);  // OFF initially

  //arm stepper pinmodes:

  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);

  //arm stepper pinmodes:

  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  // drive pinmodes :

  pinMode(pwmLF, OUTPUT);
  pinMode(pwmRF, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dirLF, OUTPUT);
  pinMode(dirRF, OUTPUT);
  pinMode(dirB, OUTPUT);

  // shooter motor pinmodes :

  pinMode(pwm, OUTPUT);
  pinMode(Dir, OUTPUT);

  //initializing shooter motor:

  digitalWrite(Dir, LOW);  // Ensure direction is set initially
  analogWrite(pwm, 0);     // Ensure motor starts stopped
  Serial.println("System initialized. Motor is OFF.");

  //ps5 drive controls:

  Lx = ps5.LStickX();
  Ly = ps5.LStickY();
  Ry = ps5.RStickY();
  Rx = ps5.RStickX();

  /*if (ps5.isConnected()) {
    Serial.println("Connected!");
  }*/

  while (!ps5.isConnected()) {
    Serial.println("Connecting to PS5 Controller...");
    delay(500);
  }
  Serial.println("Connected to PS5 Controller!");

  
  digitalWrite(Dir, HIGH); // Ensure direction is set initially
  analogWrite(pwm, NULL); // Ensure motor starts stopped
  Serial.println("System initialized. Motor is OFF.");


}
bool current_state = ps5.Options()
bool mode = 0;
bool prev_state = 0;

void toggle(current_state){
  if(current_state && !prev_state){
    mode = !mode;
  }
  prev_state = current_state;
}

void loop() {



    Lx = ps5.LStickX();
    Ly = ps5.LStickY();
    Ry = ps5.RStickY();
    Rx = ps5.RStickX();

    if (ps5.Up() || ps5.Down()) {  //for relay
      relay();
    }

    if (ps5.Square() || ps5.Circle()) {  //for arm shooter
      stepper_arm();
    }

    if (ps5.Triangle() || ps5.Cross()) {  //for shooter stepper
      stepper_shooter();
    }

    if (Lx || Ly || Ry || Rx) {  //for 3 wheel drive
      driveconditions();
    }

    /*if (ps5.L2()) {  // for shooter bldc
      //Serial.println("Shoot");
      shooter_bldc();
    }

    else {
      analogWrite(pwm, 0);
    }*/

    if (ps5.L2() && ps5.R2()) {    //simultaneous function
      shooter_1();
    }

    if ((ps5.L2() && ps5.R2()) && (ps5.L2() || ps5.Up() || ps5.Circle() || ps5.Square())  ){
      integrated_3();
    }
    //integrated_4();
    //shooter_bldc();
    v4_shooter();
}