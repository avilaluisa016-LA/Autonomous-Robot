# Autonomous Robot

An autonomous obstacle-avoidance robot built on Arduino. The robot uses an ultrasonic sensor to continuously gauge the distance of nearby objects and adjusts motor behavior accordingly — slowing down, stopping, or turning to navigate around obstacles in real time.

This project was developed as a learning exercise in embedded systems, hardware module integration, and working with third-party libraries. It serves as a foundation to be revisited and expanded upon as skills develop.

---

## Features

- **Real-time obstacle detection** via an HC-SR04 ultrasonic sensor using the `NewPing` library
- **Proportional motor response** — motor speed and direction are adjusted based on measured distance
- **Servo-mounted sensor** — the ultrasonic sensor sweeps left and right to assess the environment before choosing a direction
- **DC motor control** via the Adafruit Motor Shield V2 (`Adafruit_MotorShield` library)
- **Modular, readable code** structured for future extension and improvement

---

## Hardware Requirements

| Component | Details |
|---|---|
| Microcontroller | Arduino Uno (or compatible) |
| Motor Shield | Adafruit Motor Shield V2 |
| Ultrasonic Sensor | HC-SR04 |
| Servo Motor | Standard hobby servo (e.g. SG90) |
| DC Motors | 2x or 4x depending on chassis |
| Chassis | Any compatible 2WD or 4WD robot chassis |
| Power Supply | Battery pack suitable for motors and Arduino |

---

## Software & Libraries

The following libraries are required and must be installed before compiling:

| Library | Purpose |
|---|---|
| [`NewPing`](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home) | Ultrasonic sensor distance measurement |
| [`Servo`](https://www.arduino.cc/reference/en/libraries/servo/) | Servo motor control |
| [`Adafruit Motor Shield V2`](https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library) | DC motor control via the motor shield |
---

## Installation & Usage

### 1. Install the Arduino IDE

Download and install the [Arduino IDE](https://www.arduino.cc/en/software) if you have not already.

### 2. Install Required Libraries

Open the Arduino IDE and navigate to **Sketch → Include Library → Manage Libraries**, then search for and install:

- `NewPing` by Tim Eckel
- `Adafruit Motor Shield V2` by Adafruit
- `Servo` (included with the Arduino IDE by default)

### 3. Wire the Hardware

- Mount the Adafruit Motor Shield V2 onto the Arduino
- Connect the DC motors to the motor shield output terminals
- Attach the HC-SR04 ultrasonic sensor to the servo motor
- Connect the servo to a PWM-capable pin on the Arduino
- Connect the HC-SR04 trigger and echo pins to the designated digital pins in the sketch
- Power the Arduino and motor shield appropriately (separate power for motors is recommended)

### 4. Upload the Sketch

1. Clone or download this repository
2. Open the `.ino` file in the Arduino IDE
3. Select the correct board and port under **Tools**
4. Click **Upload**

### 5. Run the Robot

Once uploaded, place the robot on a flat surface and power it on. The robot will begin scanning its environment and navigating autonomously.

---

## Project Goals & Reflections

This project was built with the following learning objectives in mind:

- Gain hands-on experience with embedded systems and microcontroller programming
- Understand how hardware modules (sensors, servos, motor drivers) communicate and integrate
- Practice using third-party libraries to accelerate development

This is an early iteration. The project will be revisited in the future with improvements to navigation logic, code structure, and overall capability as experience grows.

---

## License

This project is open source and available under the [MIT License](LICENSE).
