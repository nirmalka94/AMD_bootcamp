# Day 3 — STL and Data Structures

**Theme:** Build a small fleet state manager using standard containers and algorithms.

## Learning outcomes
- Choose between `std::vector` and `std::unordered_map`, and recognise when an ordered `std::map`/`std::set` fits better (OPTIONAL theory).
- Insert, find, and update records safely, without accidentally inserting map keys.
- Use iterators and range-based loops.
- Apply standard algorithms such as `std::sort`, `std::find_if`, and `std::count_if`.
- Explain the basic time-complexity trade-offs of vector and hash-map operations.

## Main assignment
Complete `starter/fleet_manager.cpp`. Store robot states with unique IDs, update state, find robots by ID, list low-battery robots, and return all IDs in sorted order.

## Schedule (about 5.5 focused hours)
| Block | Duration | Activity |
|---|---:|---|
| 1 | 55 min | CORE theory |
| 2 | 30 min | Container and iterator walkthrough |
| 3 | 100 min | Main assignment |
| 4 | 15 min | Break |
| 5 | 60 min | Two challenges |
| 6 | 50 min | Cumulative exam |
| 7 | 15 min | Review |

## Completion criteria
- Robot IDs are unique in the manager.
- Updating an unknown ID does not silently create a record.
- Low-battery query returns only robots below the supplied threshold.
- Sorted output is deterministic.
- No manual memory management.
