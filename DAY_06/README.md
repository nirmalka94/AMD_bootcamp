# Day 6 — ROS 2 C++ Application Development

**Theme:** Build a compact robot status node using a publisher, subscriber, timer, and service.

## Learning outcomes
- Structure a ROS 2 C++ node as a class.
- Use publishers, subscriptions, timers, and a service callback.
- Understand callback-driven execution and basic executor behaviour.
- Use smart pointers for ROS 2 entities and understand node lifetime.
- Build and run a package with `colcon`.

## Main assignment
Complete the `robot_status_node` package. The node periodically publishes a status message, receives a simple command, and exposes a SetBool service to enable or disable status publishing.

## Environment
Requires ROS 2 Humble or Jazzy, a working C++ toolchain, and `colcon`. Source the relevant ROS 2 setup file before building. The package uses standard message packages `std_msgs` and `std_srvs`.

## Schedule (about 5.5 focused hours; ROS installation is prerequisite)
| Block | Duration | Activity |
|---|---:|---|
| 1 | 50 min | CORE theory |
| 2 | 30 min | Node lifecycle and callback walkthrough |
| 3 | 110 min | Main assignment |
| 4 | 15 min | Break |
| 5 | 55 min | Two challenges |
| 6 | 50 min | Cumulative exam |
| 7 | 15 min | Review |

## Completion criteria
- Package builds with `colcon`.
- Node publishes status periodically while enabled.
- Command subscription updates the node's state.
- Service toggles publishing and returns a useful response.
- Callbacks do not block for long periods.
- Can explain what the executor does at a high level.

## If ROS 2 is not installed
Do not spend the entire study day installing middleware. Complete the portable exercise in `starter/portable_status_logic.cpp` instead. It contains the same state machine as the node, with TODO callbacks driven by a small serial executor that behaves like the ROS 2 single-threaded executor. It ends with self-checks. Then treat the ROS package as a follow-up environment task.
