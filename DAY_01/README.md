# Day 1 — C++ Fundamentals through Robot Telemetry

**Theme:** Read sensor-like input, process it, and report a simple robot status.

## Learning outcomes
By the end of today, you should be able to:
1. Write and compile a small C++17 program independently.
2. Use variables, fundamental types, conditions, loops, functions, and `std::string`.
3. Use `std::vector` to store a changing number of readings.
4. Pass values by value and by `const` reference, and explain the difference.
5. Read compiler errors and use simple print-based debugging.

## Prerequisites
Basic programming logic. No prior C++ mastery is assumed.

## Schedule (about 5.5 focused hours)
| Block | Duration | Activity |
|---|---:|---|
| 1 | 50 min | CORE theory |
| 2 | 30 min | Walk through the starter program |
| 3 | 100 min | Main assignment: telemetry analyser |
| 4 | 15 min | Break |
| 5 | 60 min | Two mandatory challenges |
| 6 | 50 min | Cumulative exam |
| 7 | 15 min | Review and explain your solution aloud |

## Main assignment
Complete `starter/telemetry_analyser.cpp`. It reads a fixed set of distance readings, calculates the minimum, maximum, and average, and classifies the robot state.

## Deliverables
- A working telemetry analyser.
- Two completed challenges.
- A completed exam.
- A short verbal explanation of your code (2–3 minutes).

## Completion criteria
- Compiles with `-std=c++17 -Wall -Wextra -Wpedantic`.
- Handles an empty vector safely in the average function.
- Uses functions rather than putting all logic in `main`.
- Can explain why the readings vector is passed by `const` reference.
