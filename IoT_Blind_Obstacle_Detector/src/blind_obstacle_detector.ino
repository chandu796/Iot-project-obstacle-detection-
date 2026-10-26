/*
  IoT Blind Obstacle Detector — classroom prototype
  Board: Arduino Uno/Nano (5 V)
  Sensor: HC-SR04
  Alert: active buzzer; optional vibration motor through a transistor driver

  Pins:
    HC-SR04 TRIG -> D9
    HC-SR04 ECHO -> D10
    Active buzzer -> D6
    Optional motor driver control -> D5

  Educational prototype only; not a certified mobility aid.
*/

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const byte BUZZER_PIN = 6;
const byte MOTOR_PIN = 5;

const bool ENABLE_VIBRATION = true;

// Distance thresholds in centimetres.
const float FAR_LIMIT_CM = 150.0;
const float MEDIUM_LIMIT_CM = 80.0;
const float NEAR_LIMIT_CM = 40.0;
const float VERY_NEAR_LIMIT_CM = 20.0;

const unsigned long SENSOR_INTERVAL_MS = 80;
unsigned long lastSensorRead = 0;
float distanceCm = -1.0;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Timeout prevents the sketch from hanging if no echo returns.
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 25000UL);
  if (duration == 0) {
    return -1.0; // no valid echo
  }

  // Approximate speed of sound: 0.0343 cm per microsecond.
  return (duration * 0.0343f) / 2.0f;
}

void setAlert(bool buzzerOn, bool vibrationOn) {
  digitalWrite(BUZZER_PIN, buzzerOn ? HIGH : LOW);
  if (ENABLE_VIBRATION) {
    digitalWrite(MOTOR_PIN, vibrationOn ? HIGH : LOW);
  } else {
    digitalWrite(MOTOR_PIN, LOW);
  }
}

void updateAlert(float cm) {
  // Fail quiet on invalid/no echo; consider adding a separate fault indicator
  // if your project needs to distinguish "no obstacle" from "no reading".
  if (cm < 0 || cm > FAR_LIMIT_CM) {
    setAlert(false, false);
    return;
  }

  if (cm <= VERY_NEAR_LIMIT_CM) {
    setAlert(true, true); // continuous urgent alert
    return;
  }

  unsigned long onMs;
  unsigned long offMs;

  if (cm <= NEAR_LIMIT_CM) {
    onMs = 140;
    offMs = 80;
  } else if (cm <= MEDIUM_LIMIT_CM) {
    onMs = 120;
    offMs = 250;
  } else {
    onMs = 100;
    offMs = 650;
  }

  unsigned long phase = millis() % (onMs + offMs);
  bool active = phase < onMs;
  setAlert(active, active);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  setAlert(false, false);

  Serial.begin(9600);
  Serial.println(F("Blind Obstacle Detector ready"));
}

void loop() {
  unsigned long now = millis();

  if (now - lastSensorRead >= SENSOR_INTERVAL_MS) {
    lastSensorRead = now;
    distanceCm = readDistanceCm();

    Serial.print(F("Distance (cm): "));
    if (distanceCm < 0) {
      Serial.println(F("No echo / invalid reading"));
    } else {
      Serial.println(distanceCm, 1);
    }
  }

  updateAlert(distanceCm);
}
