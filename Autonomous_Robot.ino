/*ARDUINO OBSTACLE AVOIDING CAR v2
  Updated from the original to incorporate Adafruit boards:
   https://projecthub.arduino.cc/parushbansal007/arduino-obstacle-avoiding-car-473e4d
  This time I am setting things to better cycle through protocols.
  As well as fixing the wheel's speed
*/

#include <Adafruit_MotorShield.h>
#include <NewPing.h>
#include <Servo.h>

uint8_t TRIG_PIN = A0;
uint8_t ECHO_PIN = A1;
const uint8_t MAX_DISTANCE = 200;
const uint8_t MAX_SPEEDL = 200;
const uint8_t MAX_SPEEDR = 190;  // sets speed of DC  motors
const uint8_t MAX_SPEED_OFFSET = 20;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  // Ultrasonic sensor

Adafruit_MotorShield AFMS = Adafruit_MotorShield();  // AFMS v2

Adafruit_DCMotor *Lmotor1 = AFMS.getMotor(1);  // Left DCM
Adafruit_DCMotor *Rmotor2 = AFMS.getMotor(2);  // Right DCM

Servo servo1;  // Servo is connected to AFMS

bool goesForward = false;
uint8_t distance = 100;
volatile int speedSetL = 0;
volatile int speedSetR = 0;

void setup() {
  // DC Motors
  AFMS.begin();

  // Servo
  servo1.attach(10);  // Connected to Servo1 on AFMS
  servo1.write(90);
  delay(2000);

  // Ultrasonic Sensor
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  volatile uint8_t distanceR = 0;
  volatile uint8_t distanceL = 0;
  delay(40);

  do {
    if (distance <= 15) {
      moveStop();
      delay(100);
      moveBackward();
      delay(300);
      moveStop();
      delay(200);
      distanceR = lookRight();
      delay(200);
      distanceL = lookLeft();
      delay(200);

      if (distanceR >= distanceL) {
        turnRight();
        moveStop();
      } else {
        turnLeft();
        moveStop();
      }
    } else {
      moveForward();
    }
  } while (distance = readPing());
}  // loop

// Servo Movements
int lookRight() {
  servo1.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo1.write(90);
  return distance;
}

int lookLeft() {
  servo1.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo1.write(90);
  return distance;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

// Directions
void moveStop() {
  Lmotor1->run(RELEASE);
  Rmotor2->run(RELEASE);
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    Lmotor1->run(FORWARD);  // Gives the direction
    Rmotor2->run(FORWARD);
    for (speedSetL = 0; speedSetL < MAX_SPEEDL; speedSetL += 2) {  // slowly bring the speed up Motor 1
      Lmotor1->setSpeed(speedSetL);
      // Rmotor2 -> setSpeed(speedSet);
      delay(5);
    }
    for (speedSetR = 0; speedSetR < MAX_SPEEDR; speedSetR += 2) {  // slowly bring the speed up for Motor 2
      Rmotor2->setSpeed(speedSetR);
      delay(5);
    }  // For
  }    // If
}

void moveBackward() {
  goesForward = false;
  Lmotor1->run(BACKWARD);  // Give the direction
  Rmotor2->run(BACKWARD);
  for (speedSetL = 0; speedSetL < MAX_SPEEDL; speedSetL += 2) {  // slowly bring the speed up Motor 1
    Lmotor1->setSpeed(speedSetL);
    // Rmotor2 -> setSpeed(speedSet);
    delay(5);
  }
  for (speedSetR = 0; speedSetR < MAX_SPEEDR; speedSetR += 2) {  // slowly bring the speed up for Motor 2
    Rmotor2->setSpeed(speedSetR);
    delay(5);
  }  // For
}

void turnRight() {
  Lmotor1->run(FORWARD);
  Rmotor2->run(BACKWARD);
  delay(500);
  Lmotor1->run(FORWARD);
  Rmotor2->run(FORWARD);
}

void turnLeft() {
  Lmotor1->run(BACKWARD);
  Rmotor2->run(FORWARD);
  delay(500);
  Lmotor1->run(FORWARD);
  Rmotor2->run(FORWARD);
}
