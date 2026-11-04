# Day 1 Exam — Model Answers

Use these after you have finished the exam. An answer earns the mark if it contains the **key point** in bold; wording does not need to match.

## Part A — Coding
See `calculate_rms` in `solutions.cpp`. Full marks need: squares summed in a `double`, the mean taken over `values.size()`, `std::sqrt` applied once at the end, and `0.0` returned for empty input before any division.

## Part B — Debugging
1. **`i <= values.size()` reads one element past the end.** The last valid index is `size() - 1`, so the final iteration is an out-of-bounds read (undefined behaviour).
2. **Empty input divides by zero.** `0.0 / 0` gives NaN for `double`. With the `<=` bug, an empty vector also reads `values[0]`, which does not exist.

Fix (also in `solutions.cpp`):
```cpp
double average(const std::vector<double>& values) {
    if (values.empty()) return 0.0;
    double total = 0.0;
    for (double value : values) total += value;
    return total / static_cast<double>(values.size());
}
```
The guard returns before the division, and the range-based loop cannot go out of bounds.

## Part C — Technical questions
1. **`main()` is the program's entry point.** Its return value becomes the process exit status; `0` means success.
2. **`int` stores whole numbers; `double` stores floating-point values with a fractional part** (about 15–16 significant digits). Integer division truncates, for example `7 / 2 == 3`.
3. **When the number of elements is not known at compile time or changes at run time.** `std::vector` also manages its own memory, knows its size, and can be passed and returned like any other value.
4. **The function promises not to modify the argument through that parameter**, and the compiler enforces the promise. On a reference it also lets the caller pass temporaries.
5. **By value, the function gets its own copy and changes do not affect the caller. By reference, the parameter is an alias for the caller's object**: no copy is made, and changes are visible unless the reference is `const`.
6. **Dividing by a size of zero is invalid**: it gives NaN for `double`, and integer division by zero is undefined behaviour. Reading the first element of an empty vector is also undefined behaviour.
7. **It appends an element to the end and increases `size()` by one.** It may reallocate storage, which invalidates existing references and iterators.
8. **Accessing an index outside `[0, size())`.** It is undefined behaviour: it may crash, return garbage, or appear to work. Check the bounds, or use `.at()`, which throws.
9. **It states what type the function gives back to its caller**, so the compiler can check every `return` and every use of the result. `void` means nothing is returned.
10. **They enable extra warnings about suspicious code**, such as unused variables, signed/unsigned comparisons and missing returns, so bugs are caught at compile time.
