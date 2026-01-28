#include <ESP32Servo.h>

const int SENSOR_PIN = 13; 
const int SERVO_PIN = 12;
const int LED_PIN = 2; // Internal Blue LED

Servo myRobotServo;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  myRobotServo.attach(SERVO_PIN);

  // STAGE 1: POWER TEST
  // Jaws will move and LED will blink ONCE to prove board/motor are fine.
  digitalWrite(LED_PIN, HIGH);
  myRobotServo.write(120); // Close
  delay(500);
  myRobotServo.write(60);  // Open
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // STAGE 2: LIVE SENSOR MONITORING
  int val = digitalRead(SENSOR_PIN);
  
  if (val == HIGH) {
    digitalWrite(LED_PIN, HIGH); // LED ON = SENSOR WORKING
    myRobotServo.write(120);     // Close jaws
  } else {
    digitalWrite(LED_PIN, LOW);  // LED OFF = NO MOTION
    myRobotServo.write(60);      // Open jaws
  }
}
