# Day 6 Starter

The ROS 2 package is under `robot_status_node/`. Build it inside a sourced ROS 2 workspace using `colcon`; see `../IMPLEMENTATION.md`.

If ROS 2 is unavailable, complete the portable exercise instead. `StatusLogic` has three TODO callbacks (command, enable-status service, timer). `main` drives them through `SerialExecutor`, which runs one callback at a time in the order posted, like the ROS 2 single-threaded executor.
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic portable_status_logic.cpp -o status_logic
./status_logic
```
Until you implement a callback, the compiler warns that its parameter is unused; that is expected.
