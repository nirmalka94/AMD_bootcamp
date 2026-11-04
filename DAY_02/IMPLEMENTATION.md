# Day 2 Implementation — Distance Sensor Model

## Goal
Complete `starter/sensor_demo.cpp`. Implement a class that keeps its state valid and exposes a small, predictable interface.

## Step 1 — Inspect the class
Find:
- private members `name_` and `last_reading_m_`;
- constructor declaration;
- `update_reading`, `reading`, and `status` methods.

## Step 2 — Implement the constructor
Initialise the name and initial reading using a member initialiser list. Use `0.0` as the initial reading.

## Step 3 — Validate updates
`update_reading(value)` should:
- accept values from `0.0` through `20.0`, inclusive;
- update the stored reading and return `true` for valid input;
- leave the previous reading unchanged and return `false` for invalid input.

## Step 4 — Implement status
Use these rules:
- `STOP`: reading < 0.20 m.
- `SLOW`: reading >= 0.20 m and < 0.50 m.
- `NORMAL`: reading >= 0.50 m.

## Step 5 — Use the class
In `main`, create a local `DistanceSensor`, update it with a valid and invalid reading, and print the name, current reading, and status.

## Step 6 — Demonstrate exclusive ownership
Create a `std::unique_ptr<DistanceSensor>` with `std::make_unique`. Print its reading. Do not use raw `new` or `delete`.

## Step 7 — Build and test

```bash
cd starter
g++ -std=c++17 -Wall -Wextra -Wpedantic sensor_demo.cpp -o sensor_demo
./sensor_demo
```

## Expected behaviour
- A valid update changes the stored reading.
- An invalid update is rejected.
- The last valid reading remains unchanged after an invalid update.
- Status reflects the current reading.
- Program exits without manual cleanup code.
- The final line reads `Day 2 sensor model: 12/12 checks passed`.

## Explain aloud
1. When is the local sensor object destroyed?
2. Who owns the object managed by `unique_ptr`?
3. What happens to the source `unique_ptr` after it is moved?
4. Why is a virtual destructor important in a polymorphic base class?
