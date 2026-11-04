# Day 1 Theory — C++ Fundamentals

Legend: **CORE** is required today. **OPTIONAL** is for later review.

## 1. Program structure and compilation — CORE

A minimal C++ program:

```cpp
#include <iostream>

int main() {
    std::cout << "Robot ready\n";
    return 0;
}
```

- `#include` makes declarations from a header available.
- `main()` is the program entry point.
- `std::cout` writes to standard output.
- `return 0` conventionally indicates success.

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic telemetry_analyser.cpp -o telemetry
./telemetry
```

Treat compiler warnings as useful feedback. Read the **first** error first; later errors may be consequences.

## 2. Variables and types — CORE

```cpp
int sensor_count = 4;
double distance_m = 1.25;
bool obstacle_detected = false;
char mode = 'A';
std::string robot_name = "Scout";
```

Use `int` for ordinary integer counts, `double` for measurements, `bool` for true/false state, and `std::string` for text. Prefer meaningful names and initialise variables.

## 3. Conditions and loops — CORE

```cpp
if (distance_m < 0.30) {
    std::cout << "Obstacle nearby\n";
} else {
    std::cout << "Path clear\n";
}

for (int i = 0; i < 3; ++i) {
    std::cout << i << '\n';
}
```

Use `if/else` for decisions, `for` when the number of iterations is known, and `while` when repetition depends on a condition.

## 4. Functions — CORE

A function gives a piece of logic a name and a clear input/output contract.

```cpp
double to_centimetres(double metres) {
    return metres * 100.0;
}
```

- Return type: `double`.
- Function name: `to_centimetres`.
- Parameter: `metres`.
- Return value: converted measurement.

Keep functions focused. A function should normally do one understandable job.

## 5. `std::vector` and `std::string` — CORE

```cpp
#include <vector>
#include <string>

std::vector<double> readings{0.4, 0.8, 0.2};
readings.push_back(0.6);

std::string frame = "base_link";
```

`std::vector<T>` is a dynamically sized sequence of `T`. Use `.size()` for its element count and `.empty()` to test whether it has elements. Use `readings[i]` only when `i` is a valid index.

## 6. Passing arguments — CORE

```cpp
void print_readings(const std::vector<double>& readings);
```

- Pass a small type such as `int` or `double` by value.
- Pass a potentially large object such as a vector by `const` reference when the function only needs to read it.
- `const` communicates that the function will not modify the object through that reference.

A reference is an alias to an existing object; it does not make a copy.

## 7. Basic defensive programming — CORE

Check assumptions at boundaries:
- Is the vector empty before dividing by its size?
- Is an index within range?
- Is a measurement in a sensible range?

Do not add elaborate error-handling frameworks today. A clear guard clause is enough.

## 8. Debugging basics — CORE

When output is wrong:
1. Reproduce the issue with a small input.
2. Print intermediate values.
3. Check loop bounds and initial values.
4. Check whether a function receives the intended input.
5. Recompile and rerun after each focused change.

## 9. Extra material — OPTIONAL
- `std::array` for fixed-size collections.
- `auto` for type deduction when the type is obvious.
- `enum class` for strongly typed states.

Do not spend time on these unless the CORE work is complete.
