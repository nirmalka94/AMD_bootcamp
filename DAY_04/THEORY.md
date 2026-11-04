# Day 4 Theory — Interview Problem-Solving Patterns

Legend: **CORE** required; **OPTIONAL** later review.

## 1. A repeatable problem-solving loop — CORE
1. Restate the input, output, and constraints.
2. Work through a small example manually.
3. Describe a correct brute-force approach.
4. Identify the bottleneck.
5. Choose a data structure or pattern.
6. State complexity.
7. Test empty, smallest, duplicate, boundary, and invalid cases.

## 2. Hash-map lookup — CORE
Use a hash map when you need fast average lookup by key, such as checking whether a complement has already been seen. Typical average time is O(1) per lookup/insert.

## 3. Two pointers — CORE
Use two indices that move through a sequence. Common when input is sorted or when processing from both ends. Example: pair sum in a sorted array can be solved in O(n) after sorting.

## 4. Sliding window — CORE
Maintain a contiguous window and update its state as the left/right boundaries move. Useful for fixed-size windows and some variable-size constraints. Avoid recomputing the entire window on every step.

## 5. Stack — CORE
A last-in-first-out structure. Useful for matching delimiters, undo operations, and monotonic-stack problems. For delimiter validation, push opening symbols and match each closing symbol with the top.

## 6. Binary search — CORE
For a sorted range, repeatedly discard half the remaining search space. Time complexity O(log n). Be precise about inclusive/exclusive bounds and termination.

## 7. Complexity and correctness — CORE
Explain both:
- Time: how the number of operations scales with input size.
- Space: how much additional memory is used.

A solution that is fast but fails duplicates or empty input is not correct.

## 8. OPTIONAL
Recursion, tree traversal, graph BFS/DFS, heaps, dynamic programming, and advanced monotonic-stack patterns. These are useful interview topics but not required for today's core assignment.
