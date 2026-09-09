# Proximity-Controlled Watch Winder

An automatic watch winder built with an Arduino, an ultrasonic sensor, and a stepper motor. Instead of running on a fixed timer, the winder spins only when nothing is detected nearby, simulating the motion a watch needs to stay wound while idle, and stops automatically once something is placed close to the sensor.

## Overview

The ultrasonic sensor continuously measures the distance to whatever is in front of it. When that distance is greater than a set threshold (meaning nothing is nearby), the stepper motor steps continuously to keep the winder turning. As soon as an object comes within range, winding stops.

## Hardware

- Arduino (Uno or compatible)
- Ultrasonic distance sensor (HC-SR04 or compatible)
- Stepper motor + driver

### Wiring

| Component      | Arduino Pin |
|-----------------|-------------|
| Sensor Trig     | 6           |
| Sensor Echo     | 7           |
| Motor Dir       | 12          |
| Motor Step      | 13          |

## How It Works

1. The sensor is triggered with a short pulse on the `trig` pin.
2. The `echo` pin returns a pulse whose duration corresponds to the round-trip time of the sound wave.
3. That duration is converted into a distance in centimeters.
4. If the distance is greater than 5 cm (nothing detected nearby), the stepper motor is pulsed to advance one step.
5. This repeats continuously in the main loop, so the motor only turns while the sensor's field of view is clear.

The motor is configured for 200 steps per full rotation, with step pulses spaced by a fixed delay to control rotation speed.

## Getting Started

1. Wire the ultrasonic sensor and stepper driver to the Arduino according to the pinout above.
2. Open the sketch in the Arduino IDE.
3. Upload to your board.
4. Open the Serial Monitor at 115200 baud to observe distance readings (optional, for debugging).

