# Day 4 Mandatory Challenges

## Challenge 1 — First non-repeating character (25–30 minutes)
Implement:
```cpp
int first_unique_index(const std::string& text);
```
Return the index of the first character that appears exactly once, or `-1` if none exists.

Acceptance:
- `"swiss"` → `1` (`'w'`).
- `"aabb"` → `-1`.
- Empty string → `-1`.
- Preserve original character order.

## Challenge 2 — Lower-bound binary search (25–30 minutes)
Implement:
```cpp
std::size_t lower_bound_index(const std::vector<int>& sorted, int target);
```
Return the first index whose value is greater than or equal to target; return `sorted.size()` if no such index exists.

Acceptance:
- `{1, 2, 2, 4}`, target 2 → 1.
- `{1, 3, 5}`, target 4 → 2.
- Empty input → 0.

## Optional
Implement the same lower-bound operation using `std::lower_bound`, then compare the two implementations.
