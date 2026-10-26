# IoT Blind Obstacle Detector

An Arduino-based assistive prototype that detects nearby obstacles and alerts the wearer using a buzzer and an optional vibration motor.

> **Prototype note:** This repository assumes an Arduino Uno/Nano, HC-SR04 ultrasonic sensor, active buzzer, and optional vibration motor driven through a transistor. Confirm the exact components used by your team before building. This is an educational prototype, not a certified mobility aid.

## Features
- Measures approximate distance with an HC-SR04 ultrasonic sensor.
- Gives faster audible alerts as obstacles get closer.
- Supports an optional vibration motor for tactile feedback.
- Uses configurable distance thresholds in the sketch.

## Hardware
- Arduino Uno or compatible 5 V board
- HC-SR04 ultrasonic distance sensor
- Active buzzer (5 V, low current)
- Optional 3–5 V vibration motor
- NPN transistor (e.g. 2N2222/BC547) or suitable logic-level driver for the motor
- 1 kΩ base resistor for the transistor
- Flyback diode across the motor (e.g. 1N400x)
- Breadboard, jumper wires, USB power source
- Optional wearable frame/holder

## Pin connections

| Module | Module pin | Arduino pin |
|---|---|---|
| HC-SR04 | VCC | 5V |
| HC-SR04 | GND | GND |
| HC-SR04 | TRIG | D9 |
| HC-SR04 | ECHO | D10 |
| Active buzzer | + | D6 |
| Active buzzer | - | GND |
| Optional motor driver | transistor control/base via 1 kΩ resistor | D5 |
| Motor supply/driver ground | GND | GND |

**Motor wiring:** Do not connect a vibration motor directly to an Arduino I/O pin. Use a transistor/driver. Connect the motor supply as appropriate for the motor, share ground with the Arduino, and place a flyback diode across the motor (cathode to positive supply). Check the transistor pinout and motor current rating.

## Alert behaviour
- More than 150 cm: no alert
- 80–150 cm: slow beeps / intermittent vibration
- 40–80 cm: medium alert rate
- 20–40 cm: fast alert rate
- 20 cm or less: continuous alert

Thresholds are starting values for a classroom demo. Tune and test in the actual environment.

## Getting started
1. Install the Arduino IDE.
2. Open `src/blind_obstacle_detector.ino`.
3. Select your Arduino board and port.
4. Check the wiring table and upload the sketch.
5. Test using a flat object at several known distances.
6. Keep the prototype stationary during initial tests; do not rely on it for navigation.

## Repository structure
```text
IoT_Blind_Obstacle_Detector/
├── README.md
├── LICENSE
├── .gitignore
├── docs/
│   ├── circuit-and-wiring.md
│   ├── components.md
│   ├── testing-plan.md
│   └── project-report-outline.md
└── src/
    └── blind_obstacle_detector.ino
```

## Safety and limitations
- Ultrasonic sensors can miss soft, angled, narrow, or sound-absorbing objects and may perform poorly outdoors or in crowded/noisy environments.
- The sensor measures distance only within its effective field of view; it does not identify hazards or guarantee obstacle detection.
- Use this as a supervised educational prototype only. It must not replace a white cane, guide dog, trained mobility techniques, or professional assistive equipment.
- Protect the circuit from moisture and physical impact. Do not mount exposed electronics where they could injure the wearer.

## Team details
Add your team member names, USNs, group number, and institution details here before submission.

## License
Released under the MIT License; see `LICENSE`.
