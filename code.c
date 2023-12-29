{\rtf1\ansi\ansicpg1252\cocoartf2759
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica-Bold;\f1\froman\fcharset0 Times-Roman;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\b\fs26\fsmilli13333 \cf0 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include <AFMotor.h>
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 #include <SoftwareSerial.h>
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 // Motor Configuration
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 AF_DCMotor motor1(1);\'a0 // Motor connected to M1
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 AF_DCMotor motor2(2);\'a0 // Motor connected to M2
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 AF_DCMotor motor3(3);\'a0 // Motor connected to M3
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 AF_DCMotor motor4(4);\'a0 // Motor connected to M4
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 // Bluetooth Configuration
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 SoftwareSerial bluetoothSerial(10, 11); // RX, TX
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void setup() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0// Set up serial communication for debugging
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0Serial.begin(9600);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0// Set up Bluetooth communication
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0bluetoothSerial.begin(9600);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void loop() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0// Check if data is available from Bluetooth
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0if (bluetoothSerial.available() > 0) \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0char command = bluetoothSerial.read();
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0// Process the received command
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0switch (command) \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0case 'F':
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0moveForward();
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0break;
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0case 'B':
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0moveBackward();
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0break;
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0case 'L':
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0turnLeft();
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0break;
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0case 'R':
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0turnRight();
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0break;
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0case 'S':
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0stopMotors();
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\'a0\'a0\'a0\'a0break;
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\'a0\'a0\}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0\}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 // Function to move the car forward
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void moveForward() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.run(FORWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.run(FORWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.run(FORWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.run(FORWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 // Function to move the car backward
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void moveBackward() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 // Function to turn the car left
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void turnLeft() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.run(FORWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.run(FORWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 // Function to turn the car right
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void turnRight() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.run(FORWARD);
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.run(FORWARD);
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.run(BACKWARD);
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.setSpeed(255);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.run(BACKWARD);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 // Function to stop all motors
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 void stopMotors() \{
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.setSpeed(0);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor1.run(RELEASE);
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.setSpeed(0);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor2.run(RELEASE);
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.setSpeed(0);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor3.run(RELEASE);
\f1\b0\fs24 \
\

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.setSpeed(0);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \'a0\'a0motor4.run(RELEASE);
\f1\b0\fs24 \

\f0\b\fs26\fsmilli13333 \}
\f1\b0\fs24 \
\
\
\
}
