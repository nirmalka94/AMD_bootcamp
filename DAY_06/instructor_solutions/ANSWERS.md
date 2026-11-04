# Day 6 — Reference Solutions and Exam Model Answers

## Files in this folder
| File | Covers |
|---|---|
| `robot_status_node.cpp` | Main assignment |
| `robot_status_node_challenges.cpp` | Challenges 1 and 2 |
| `cmd_vel_listener.cpp` | Exam Part A |
| `portable_status_logic.cpp` | Portable fallback (no ROS 2) |
| `package.xml`, `CMakeLists.txt` | Builds the three nodes as package `robot_status_node_solutions` |

Build all of them from the course root with `make ros` (source ROS 2 first).

## Challenges — what to look for
- **Challenge 1:** `/robot/battery` (`std_msgs/msg/Int32`) is handled by its own subscription callback, which **writes** `battery_percent_`. The timer callback `publish_status` **reads** it. Out-of-range values are logged and ignored, so the last valid value is kept. Before the first reading the status says `battery unknown` rather than inventing a value.
- **Challenge 2:** only `START` and `STOP` increment counters. Under the default single-threaded executor callbacks never overlap, so plain `int` members are safe. With a `MultiThreadedExecutor` and a reentrant callback group, or the command and timer callbacks in different groups, those members would need a mutex or atomics.

Expected status after `START`, `JUMP`, `STOP`, battery `15`, and an ignored battery `140`:
```
STOP | battery 15% LOW | start 1 stop 1
```

## Exam Part A — Coding
See `cmd_vel_listener.cpp`. Full marks need: a class deriving from `rclcpp::Node`, the subscription stored as a member `SharedPtr`, a callback taking `geometry_msgs::msg::Twist::ConstSharedPtr` (or `const Twist&`) that copies `linear.x` and `angular.z` into members, and a short callback body.

The package must also declare the dependency:
```xml
<depend>geometry_msgs</depend>
```
```cmake
find_package(geometry_msgs REQUIRED)
ament_target_dependencies(cmd_vel_listener rclcpp geometry_msgs)
```

## Exam Part B — Debugging
**A single-threaded executor runs one callback at a time, so nothing else runs for those 5 seconds.** Timer callbacks fire late and then bunch up, so status publishing stalls. Incoming messages queue in the middleware; with history depth 10, older ones are dropped. Service clients wait and may time out.

Any one improvement earns the mark:
- hand the work to a worker thread (the callback enqueues and returns);
- model the operation as an **action**, so it reports feedback and can be cancelled;
- use a `MultiThreadedExecutor` with the slow callback in its own callback group, synchronising any shared state.

## Part C — Technical questions
1. **A named participant in the ROS graph that owns publishers, subscriptions, timers, services and parameters.** In `rclcpp` it is typically a class deriving from `rclcpp::Node`.
2. **A topic is an asynchronous, many-to-many stream of messages; a service is a request/response exchange with one server and one reply per request.**
3. **It sends messages of one type on a topic to every matching subscriber**, without knowing who they are.
4. **The executor calls it when a message arrives**; it should do short work, such as updating state or handing work off.
5. **It runs a callback periodically.** `create_wall_timer` uses the steady wall clock; `create_timer` follows the node's clock, which can be simulation time. Timer callbacks run on the executor, so they can be delayed.
6. **It waits for ready work (messages, timers, service requests) and dispatches the matching callbacks** on its thread or threads. `rclcpp::spin` runs one.
7. **Single-threaded runs callbacks one at a time on one thread. Multi-threaded uses a thread pool, so callbacks in different or reentrant callback groups can run at the same time.**
8. **If two callbacks run concurrently on different threads and touch the same member, unsynchronised access is a data race.** Use a mutex, atomics, or a mutually exclusive callback group.
9. **Delivery behaviour**: reliability (reliable or best effort), durability (volatile, or transient-local so late joiners get the last messages), history and depth, and deadline/liveliness. A publisher and subscriber with incompatible QoS do not connect.
10. **For a long-running goal that needs progress feedback or cancellation**, such as navigating to a pose. Service callbacks should return quickly.
