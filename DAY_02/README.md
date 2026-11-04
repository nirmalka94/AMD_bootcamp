# Day 2 — Classes, Object Lifetime, and Resource Ownership

**Theme:** Model a robot sensor as a C++ object with a clear lifetime and ownership model.

## Learning outcomes
By the end of today, you should be able to:
1. Define a class with private data and public methods.
2. Explain constructors, destructors, and object lifetime.
3. Distinguish stack objects from dynamically allocated objects.
4. Explain why copying a raw owning pointer is dangerous.
5. Use RAII and `std::unique_ptr` for simple exclusive ownership.
6. Explain when a base class needs a virtual destructor.

## Prerequisites
Day 1 fundamentals: functions, vectors, references, and compilation.

## Schedule (about 5.5 focused hours)
| Block | Duration | Activity |
|---|---:|---|
| 1 | 55 min | CORE theory |
| 2 | 30 min | Class and object walkthrough |
| 3 | 100 min | Main assignment: sensor model |
| 4 | 15 min | Break |
| 5 | 60 min | Two mandatory challenges |
| 6 | 50 min | Cumulative exam |
| 7 | 15 min | Review and verbal explanation |

## Main assignment
Complete `starter/sensor_demo.cpp`. Implement a `DistanceSensor` class that stores a sensor name and latest reading, validates updates, and reports a status.

## Deliverables
- Working `DistanceSensor` class.
- One small ownership example using `std::unique_ptr`.
- Two challenges and exam completed.
- A short explanation of object lifetime and ownership.

## Completion criteria
- Data members are private.
- Invalid readings do not overwrite the last valid reading.
- Constructors establish a valid initial state.
- No manual `new`/`delete` is needed in the main assignment.
- Can explain why `std::unique_ptr` cannot be copied.
