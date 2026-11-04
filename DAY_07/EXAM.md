# Day 7 Cumulative Exam

**Time limit:** 50 minutes. **Total:** 30 marks.

## Part A — Coding (15 marks, 25 minutes)
Implement:
```cpp
bool all_finite(const std::vector<double>& values);
```
Return true only if every value is finite (not NaN and not positive/negative infinity). Empty input returns true. Use `<cmath>`.

## Part B — Debugging and diagnosis (5 marks, 10 minutes)
A process intermittently crashes on a robot but works on a desktop. List the first five pieces of information or experiments you would collect. Include at least one build/runtime diagnostic tool and explain why reproducing on the target matters.

## Part C — Technical questions (10 marks, 15 minutes)
1. Why compile with debug symbols?
2. What does AddressSanitizer help detect?
3. What is a stack trace?
4. When is GDB useful?
5. What does `ldd` show?
6. What does `dmesg` help investigate?
7. Distinguish throughput from latency.
8. What is queue buildup in a sensor pipeline?
9. Why is CPU utilisation alone insufficient to diagnose a slowdown?
10. Name one risk of adding concurrency to a robotics application.
