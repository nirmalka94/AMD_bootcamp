# Day 8 Final Cumulative Exam

**Time limit:** 45 minutes. **Total:** 30 marks.

## Part A — Coding (15 marks, 25 minutes)
Implement:
```cpp
std::vector<int> most_frequent(const std::vector<int>& values,
                               std::size_t k);
```
Return up to `k` distinct values with highest frequency. Break frequency ties by ascending numeric value. Empty input or `k == 0` returns empty.

Explain your time and space complexity. A straightforward solution is acceptable if correct and well explained.

## Part B — Debugging/design (5 marks, 8 minutes)
A function returns a reference to a local variable. Explain why this is invalid and propose a safe alternative based on whether the caller needs ownership or only a view.

## Part C — Technical questions (10 marks, 12 minutes)
1. Explain RAII.
2. When should a base class destructor be virtual?
3. Compare vector and unordered_map.
4. Explain one use of a sliding window.
5. What is a data race?
6. What is the role of an executor in ROS 2?
7. Distinguish throughput and latency.
8. How would you investigate a sudden FPS drop?
9. What makes a callback unsafe to block?
10. Describe one C++ design decision from a robotics project and its trade-off.
