# Day 3 Cumulative Exam

**Time limit:** 50 minutes. **Total:** 30 marks.

## Part A — Coding (15 marks, 25 minutes)
Implement:
```cpp
std::vector<int> unique_sorted(const std::vector<int>& values);
```
Return the distinct values in ascending order. Do not modify the input. Empty input returns empty.

Test with `{4, 2, 4, 1, 2}` → `{1, 2, 4}`.

## Part B — Debugging (5 marks, 10 minutes)
Explain why this code may insert an unintended map entry:
```cpp
if (robot_battery[id] < 20) {
    std::cout << id << " needs charging\n";
}
```
Show a safer lookup when the intent is only to inspect an existing key.

## Part C — Technical questions (10 marks, 15 minutes)
1. When would you choose a vector?
2. What is the average lookup complexity of an unordered map?
3. What is the difference between `find()` and `operator[]` on a map?
4. What is an iterator?
5. What does `std::sort` require from its iterator range?
6. What does `std::count_if` return?
7. Why can vector reallocation invalidate references?
8. What is the erase-remove idiom used for?
9. What does O(n log n) describe in broad terms?
10. Why might deterministic ordering matter in logs or tests?
