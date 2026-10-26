# Circuit and Wiring Guide

## Signal connections

```text
Arduino Uno             HC-SR04
-----------             -------
5V   -----------------> VCC
GND  -----------------> GND
D9   -----------------> TRIG
D10  <----------------- ECHO

Arduino Uno             Active buzzer
-----------             -------------
D6   -----------------> +
GND  -----------------> -

Arduino D5 ---> 1 kΩ resistor ---> NPN transistor base
Motor positive ------------------> motor supply positive
Motor negative ------------------> transistor collector
Transistor emitter --------------> GND
Flyback diode across motor: cathode to motor positive, anode to motor negative
Arduino GND ----------------------> motor-driver/supply GND
```

The diagram is conceptual. Check the transistor pinout and component ratings before wiring.

## Important notes
- The HC-SR04 ECHO output is typically 5 V; this is suitable for a 5 V Arduino Uno/Nano. For 3.3 V boards, use a level shifter or voltage divider on ECHO.
- Do not power a motor directly from an Arduino pin.
- A low-current active buzzer can often be driven from a digital pin, but check its current rating. Use a transistor driver if needed.
- Disconnect USB/power before changing wiring.
- Verify all grounds are connected together when using a separate motor supply.
