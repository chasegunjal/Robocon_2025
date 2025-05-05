#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>

bool current_state = 0;
bool mode = 0;
bool prev_state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ps5.begin("88:03:4C:93:FE:13");

  while (!ps5.isConnected()) {
    Serial.println(".. Connecting..........");
    delay(500);
  }

  Serial.println("******* CONNECTED *******");
}


void toggle(bool current_state) {
  if (current_state && !prev_state) {
    mode = !mode;
  }
  prev_state = current_state;
}


void loop() {
  toggle(ps5.Options());
  if (mode == 1) {
    ps5.setLed(255, 0, 0);
    Serial.println("Controller Freezed!!!");
  } else {
    ps5.setLed(0, 0, 255);
    Serial.println("----------- Controller Active ---------");
  }
}
