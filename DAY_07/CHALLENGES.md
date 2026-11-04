# Day 7 Mandatory Challenges

## Challenge 1 — Find the first bad sample (25 minutes)
Implement:
```cpp
int first_invalid_reading(const std::vector<double>& values);
```
Return the first index containing a value outside `[0.0, 20.0]`, or `-1` if all values are valid.

Acceptance:
- Empty input → -1.
- `{1.0, 2.0, 25.0, -1.0}` → 2.
- Do not modify input.

## Challenge 2 — Rolling average (30 minutes)
Implement:
```cpp
double average_of_last_k(const std::vector<double>& values, std::size_t k);
```
Return the average of the last `k` values. Return 0 for `k == 0` or `k > values.size()`. Aim for O(k) for one query; explain how you would support repeated queries efficiently.

Acceptance:
- `{1, 2, 3, 4}`, k=2 → 3.5.
- Empty input → 0.
- No division by zero.

## Optional
Run a small benchmark and compare debug versus optimised builds. Do not infer performance from one noisy measurement.
