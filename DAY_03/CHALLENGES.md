# Day 3 Mandatory Challenges

## Challenge 1 — Frequency counter (25 minutes)
Implement:
```cpp
std::unordered_map<int, int> count_values(const std::vector<int>& values);
```
Return a map from each distinct integer to its occurrence count.

Acceptance:
- `{2, 1, 2, 3, 1, 2}` gives counts 2→3, 1→2, 3→1.
- Empty input gives an empty map.
- Do not sort the input.

## Challenge 2 — Top battery robots (30 minutes)
Implement:
```cpp
std::vector<RobotState> top_battery_robots(
    const std::vector<RobotState>& robots, std::size_t count);
```
Return up to `count` robots with the highest battery percentage. Sort descending by battery; break ties by ascending ID.

Acceptance:
- Input is unchanged.
- `count == 0` returns empty.
- If count exceeds input size, return all robots.

## Optional
Compare vector scan versus unordered_map lookup using a small benchmark. Do not optimise without measuring.
