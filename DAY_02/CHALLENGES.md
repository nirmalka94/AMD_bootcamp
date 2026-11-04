# Day 2 Mandatory Challenges

Complete both independently. Suggested time: 25–30 minutes each.

## Challenge 1 — Battery class

Implement a `Battery` class with:
- private `percentage_` member;
- constructor that clamps its initial value to `[0, 100]`;
- `bool set_percentage(int value)` that rejects out-of-range values without changing the current percentage;
- `int percentage() const`;
- `bool is_low() const`, true below 20%.

Acceptance checks:
- Constructing with 120 produces 100.
- Setting -1 returns false and preserves the previous value.
- Setting 15 returns true and `is_low()` returns true.

## Challenge 2 — Exclusive sensor ownership

Write a function:

```cpp
std::unique_ptr<DistanceSensor> make_sensor(const std::string& name);
```

Return a newly created sensor managed by `std::unique_ptr`.

Acceptance checks:
- Use `std::make_unique`.
- Do not use raw `new` or `delete`.
- Explain why returning `unique_ptr` by value is valid (ownership can be moved).

## Optional extension
Create a small abstract `SensorBase` with a virtual destructor and one pure virtual method. Implement one derived sensor. Keep this optional; do not turn it into a large class hierarchy.
