# Test Plan

## Objective
Check whether the prototype produces increasingly frequent alerts as an obstacle moves closer.

## Test setup
- Secure the sensor and circuit on a table.
- Use a broad, flat target perpendicular to the sensor.
- Measure target distance with a ruler or tape.
- Keep hands clear of exposed wiring and moving parts.

## Test cases

| Test | Target distance | Expected behaviour |
|---|---:|---|
| 1 | 180 cm | No alert |
| 2 | 120 cm | Slow intermittent alert |
| 3 | 60 cm | Medium-rate alert |
| 4 | 30 cm | Fast alert |
| 5 | 10 cm | Continuous alert |
| 6 | No target / no echo | No alert; serial monitor reports invalid reading |

Repeat each test at least five times and record observed behaviour. Test objects with different surfaces and angles to identify limitations.

## Record results
For each test, record: measured distance, alert behaviour, successful detections, missed detections, and notes.

## Acceptance criteria for classroom demonstration
- Serial monitor shows plausible distances for a broad flat target.
- Alert rate increases as the target gets closer.
- No unexpected resets or overheating occur during a 10-minute stationary test.

These criteria do not establish safety or suitability for real-world mobility.
