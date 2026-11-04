# Day 1 Cumulative Exam

**Time limit:** 50 minutes. **Total:** 30 marks. Do not open instructor solutions.

## Part A — Coding (15 marks, 25 minutes)

Implement:

```cpp
double calculate_rms(const std::vector<double>& values);
```

Use the root mean square formula: square each value, calculate the mean of the squares, then take the square root. Return `0.0` for an empty vector.

You may use `<cmath>`. Test with `{3.0, 4.0}`; expected result is approximately `3.5355339`.

## Part B — Debugging (5 marks, 10 minutes)

Find and fix the defects:

```cpp
double average(const std::vector<double>& values) {
    double total = 0.0;
    for (std::size_t i = 0; i <= values.size(); ++i) {
        total += values[i];
    }
    return total / values.size();
}
```

Explain both defects and how your fix handles empty input.

## Part C — Technical questions (10 marks, 15 minutes)

Answer briefly (1–3 sentences each):
1. What is the purpose of `main()`?
2. What is the difference between `int` and `double`?
3. When would you use `std::vector` instead of a built-in array?
4. What does `const` mean in a function parameter?
5. What is the difference between passing by value and by reference?
6. Why should you check for an empty vector before calculating an average?
7. What does `push_back()` do?
8. What is an out-of-bounds access?
9. What is the purpose of a function return type?
10. What do `-Wall -Wextra` help with?

## Self-grading
- Coding: correct formula, correct empty case, compiles, sensible names.
- Debugging: loop bound fixed and empty input handled.
- Questions: award one mark for each accurate answer.
