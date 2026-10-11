# Earthquake Alert System

An Arduino-based vibration detection and alert prototype using an MPU6050 accelerometer and gyroscope, with buzzer and LED indicators.

## Overview

The system monitors motion using the MPU6050 sensor connected to an Arduino Uno. When the measured acceleration magnitude exceeds a configured threshold for a specified duration, the system activates a buzzer and LED to indicate detected vibration.

## Hardware Components

- Arduino Uno
- MPU6050 accelerometer and gyroscope
- Buzzer
- LED
- 1 kΩ resistor
- Breadboard and jumper wires

## Working Principle

1. The MPU6050 measures acceleration and motion.
2. The Arduino reads sensor data over I²C.
3. The firmware calculates acceleration magnitude and compares it with a configured threshold.
4. When the detection condition is met, the buzzer and LED provide an alert.

## Repository Structure

- `earthquake_alert.ino` — Arduino firmware
- `docs/` — project presentation and documentation
- `images/` — circuit and system block diagrams

## Limitations

This is a basic vibration-triggered alert prototype. It has not been established as a validated earthquake prediction or early-warning system. Threshold-based detection may also respond to non-earthquake vibrations.

## Future Improvements

- Vibration data logging and analysis
- Wireless notifications
- Mobile application integration
- Improved detection algorithms and validation

## Authors

Shree Dharshan S  
Sugi Sivam S
