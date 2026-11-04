# Day 1 Mandatory Challenges

Complete both independently after the main assignment. Suggested time: 25–30 minutes each.

## Challenge 1 — Count close obstacles

Write:

```cpp
int count_close_readings(const std::vector<double>& readings,
                         double threshold);
```

Return the number of readings strictly smaller than `threshold`.

Acceptance checks:
- `{0.1, 0.4, 0.2, 0.8}`, threshold `0.3` → `2`.
- Empty vector → `0`.
- A reading exactly equal to the threshold is not counted.

## Challenge 2 — Convert and filter

Write:

```cpp
std::vector<double> valid_readings(const std::vector<double>& readings);
```

Return a new vector containing only readings in the inclusive range `[0.0, 10.0]`.

Acceptance checks:
- `{-1.0, 0.0, 1.5, 10.0, 12.0}` → `{0.0, 1.5, 10.0}`.
- Input remains unchanged.
- Empty input returns an empty vector.

## Optional extension
Add a function that converts metres to centimetres. Do not start this until both mandatory challenges pass.
