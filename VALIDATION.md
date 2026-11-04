# Course validation and known environment requirements

## Automated checks
From the course root:
```bash
make check
```
This:
- compiles every starter with `-std=c++17 -Wall -Wextra -Wpedantic -Werror` (unused parameters in TODO stubs are allowed);
- compiles each day's tests against that day's `my_solutions.cpp` template, so the templates always match what the tests call;
- builds each day's `tests/tests.cpp` against the instructor solutions with AddressSanitizer and UndefinedBehaviorSanitizer, and runs it;
- runs the Day 5 tests and the repaired Day 7 race example under ThreadSanitizer;
- runs the repaired Day 7 telemetry program, which checks itself.

ThreadSanitizer in GCC 11 can fail with `unexpected memory mapping` on kernels with high address-space randomisation. The Makefile runs TSan binaries under `setarch "$(uname -m)" -R` to avoid this.

## ROS 2
Day 6 requires an installed ROS 2 distribution. Source it, then run `make ros`. This builds two packages with `colcon`:
- `robot_status_node`: the learner's starter package;
- `robot_status_node_solutions`: the reference nodes for the assignment, both challenges, and exam Part A (`DAY_06/instructor_solutions/`).

Both packages use `ament_target_dependencies`, which works on Humble and Jazzy. Newer distributions deprecate it in favour of `target_link_libraries`.

## Solutions
Instructor solutions are reference implementations, not the only valid solutions. A learner solution should be judged against the stated contract and acceptance criteria. `make test DAY=NN SRC=DAY_NN/my_solutions.cpp` runs a day's tests against a learner's file. `make test DAY=NN` without `SRC` runs them against the instructor solutions.

## Scope
The course deliberately excludes deep template metaprogramming, custom allocators, lock-free algorithms, advanced ROS 2 composition, full TF2/action implementations, and broad dynamic-programming/graph problem sets from the mandatory path. These can be revisited after the interview-preparation sprint.
