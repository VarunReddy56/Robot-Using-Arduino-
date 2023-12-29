#include <AFMotor.h>
#include <SoftwareSerial.h>

// Motor Configuration
AF_DCMotor motor1(1);  // Motor connected to M1
AF_DCMotor motor2(2);  // Motor connected to M2
AF_DCMotor motor3(3);  // Motor connected to M3
AF_DCMotor motor4(4);  // Motor connected to M4
// Bluetooth Configuration
SoftwareSerial bluetoothSerial(10, 11); // RX, TX
void setup() {
  // Set up serial communication for debugging
  Serial.begin(9600);
  // Set up Bluetooth communication
  bluetoothSerial.begin(9600);
}
void loop() {
  // Check if data is available from Bluetooth
  if (bluetoothSerial.available() > 0) {
    char command = bluetoothSerial.read();
    // Process the received command
    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case 'S':
        stopMotors();
        break;
    }
  }
}
// Function to move the car forward
void moveForward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}
// Function to move the car backward
void moveBackward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}
// Function to turn the car left
void turnLeft() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}
// Function to turn the car right
void turnRight() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);

  motor2.setSpeed(255);
  motor2.run(FORWARD);

  motor3.setSpeed(255);
  motor3.run(BACKWARD);

  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

// Function to stop all motors
void stopMotors() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);

  motor2.setSpeed(0);
  motor2.run(RELEASE);

  motor3.setSpeed(0);
  motor3.run(RELEASE);

  motor4.setSpeed(0);
  motor4.run(RELEASE);
}



