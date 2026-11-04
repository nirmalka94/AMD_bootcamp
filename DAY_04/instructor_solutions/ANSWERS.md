# Day 4 Exam — Model Answers

Use these after you have finished the exam. An answer earns the mark if it contains the **key point** in bold.

## Part A — Coding
See `longest_unique_substring_length` in `solutions.cpp`. It keeps a window `[start, i]` without repeats and records where each character was last seen. When a repeat falls inside the window, `start` jumps past it. Each index is visited once, so the time is O(n), and the extra space is O(alphabet size).

A common bug is moving `start` backwards. With `"abba"`, the second `a` was last seen at index 0, which is already outside the window. The `it->second >= start` test prevents this.

## Part B — Debugging
**`sum` must always equal the total of the current window.** Without subtracting the outgoing value it becomes a running prefix sum. It grows with every step and includes elements that have left the window.

Required order:
1. Sum the first `k` elements once, and set `best` to that sum.
2. For each `right` from `k` to `n - 1`, add `values[right]` and subtract `values[right - k]`. The window is now `[right - k + 1, right]`.
3. Only then compare `sum` with `best`.

## Part C — Technical questions
1. **Clarify the problem**: restate the input and output, ask about constraints (size, value range, duplicates, negatives, empty input), and work through a small example.
2. **When you need average O(1) lookup by key**: "seen before?" checks, complements, frequency counts, grouping, de-duplication.
3. **Two indices move through the sequence**, either from both ends inward or in the same direction at different speeds, to replace a nested loop. It usually needs sorted input or some monotonic property, and runs in O(n).
4. **A contiguous range `[left, right]` that is updated incrementally**: extend `right`, and shrink `left` when a constraint is violated. Each element enters and leaves once, so it is O(n).
5. **The most recently opened delimiter must be closed first**, and last-in-first-out is exactly the nesting order.
6. **O(log n).**
7. **A substring is contiguous; a subsequence keeps the order but may skip characters.**
8. **Every element is compared with every other, which is quadratic work.** At n = 10⁵ that is about 10¹⁰ operations, so look for a hash map, sorting or two pointers instead.
9. Any two of: **empty input, a single element, all duplicates, negative values, already sorted or reverse sorted, values near overflow**.
10. **It establishes a correct baseline, and shows you understand the problem before optimising.** It exposes the bottleneck to improve, and leaves you with a working answer if time runs out.
