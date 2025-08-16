# Smart-Barrier

A toll gate automation system powered by an ultrasonic sensor and servo motor. When a vehicle comes within range, the system deactivates the blue LED and activates the red LED, signaling the toll gate to open. The buzzer provides an audible alert while the servo motor lifts the barrier for 1.5 seconds. 

## Features
-   **High Reactivity**
-   **Automated Gate MOtion**
-   **Audible Alerts**
-   **Indicator LEDs**

## Components Used
-   Arduino Uno
-   HC-SR04 Ultrasonic Sensor
-   Piezo Buzzer
-   Servo Motor
-   LEDs (x2)
-   220Ω Resistors (Current limiting)
-   Breadboard, Jumper Wires

## How It Works

- The servo motor is set to face downwards and the steady LED (blue) stays on.
- When an apporoaching vehicle is detected the servo raises the toll gate.
- The active LED (red) comes on and the buzzer beeps a tone.
- After 1.5 seconds if no vehicle is still detected then the system resets.

## Circuit Schematic

You can find a link to the online schematic [here](https://www.tinkercad.com/things/1XyfDf9cBiv-servo-smart-barrier?sharecode=uQ-IlKGvOhFteAmBcTdjKXaosm15e0IbY3eXXdkqTrU). Developed using TinkerCAD <sup>TM</sup>

