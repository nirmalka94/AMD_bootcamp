# Day 3 Exam — Model Answers

Use these after you have finished the exam. An answer earns the mark if it contains the **key point** in bold.

## Part A — Coding
See `unique_sorted` in `solutions.cpp`: copy, `std::sort`, then `erase(std::unique(...), end())`. That is O(n log n) time and O(n) extra space. Inserting into a `std::set` and copying out is also correct, with the same complexity.

## Part B — Debugging
**`operator[]` inserts a value-initialised entry (`0`) when the key is missing.** Checking an unknown ID therefore adds that ID to the map with battery `0`, and reports it as needing charging. `operator[]` also cannot be used on a `const` map.

Safer lookup:
```cpp
const auto it = robot_battery.find(id);
if (it != robot_battery.end() && it->second < 20) {
    std::cout << id << " needs charging\n";
}
```

## Part C — Technical questions
1. **As the default sequence container**: it is contiguous and cache-friendly, has O(1) indexed access and cheap appends, and is good for iteration-heavy work. A linear search over a small vector is often fast enough.
2. **Average O(1)**; the worst case is O(n) when many keys collide.
3. **`find()` returns an iterator (`end()` if the key is missing) and never inserts. `operator[]` returns a reference and inserts a default value if the key is missing.** `find()` also works on `const` maps.
4. **An object that refers to a position in a container** and can be dereferenced and advanced, like a generalised pointer. Algorithms take `[begin, end)` iterator ranges.
5. **Random-access iterators** (`vector`, `deque`, `array`), and elements that can be ordered with `<` or a comparator that is a strict weak ordering. `std::list` has its own `sort()` member instead.
6. **The number of elements in the range for which the predicate is true.**
7. **When `size()` would exceed `capacity()`, the vector allocates new storage, moves the elements, and frees the old block**, so references, pointers and iterators to the old elements now point to freed memory.
8. **Removing every matching element from a vector in one O(n) pass.** `remove`/`remove_if` shifts the kept elements forward and returns the new logical end, then `erase` trims the tail.
9. **Running time grows in proportion to n × log n**, which is typical for comparison sorts. Doubling n slightly more than doubles the work.
10. **Iteration order of `unordered_map`/`unordered_set` is unspecified and can differ between runs, platforms and library versions.** Deterministic output keeps logs comparable and tests reproducible.
