#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(9); // Attach servo1 to pin 9
  servo2.attach(10); // Attach servo2 to pin 10
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read();

    if (signal == 'B') { // Biodegradable waste
      servo1.write(180); // Rotate servo1 to 0 degrees
      delay(1000); // Delay for stability
      servo1.write(0); // Rotate servo1 to 90 degrees
      delay(1000); // Delay for stability
    } else if (signal == 'N') { // Non-biodegradable waste
      servo2.write(180); // Rotate servo2 to 0 degrees
      delay(1000); // Delay for stability
      servo2.write(0); // Rotate servo2 to 90 degrees
      delay(1000); // Delay for stability
    }
  }
}
