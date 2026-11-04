# Day 6 Theory — ROS 2 C++ Essentials

Legend: **CORE** required; **OPTIONAL** later review.

## 1. A ROS 2 node is a class — CORE
A typical `rclcpp` node derives from `rclcpp::Node`. Its constructor creates publishers, subscriptions, timers, and services. Keep callbacks small and delegate non-trivial logic to ordinary C++ methods.

## 2. Publishers and subscriptions — CORE
A publisher sends messages on a topic. A subscription registers a callback to receive messages. Topic names and message types must match between endpoints.

## 3. Timers — CORE
A wall timer schedules a callback periodically. Do not assume the callback runs at an exact hard real-time interval; executor load and callback duration affect timing.

## 4. Services — CORE
A service implements request/response communication. Keep service callbacks short. Use actions for long-running, feedback-producing operations; this day's assignment does not require implementing an action server.

## 5. Executors and callbacks — CORE
An executor takes ready work (subscription, timer, service callbacks) and runs it. A single-threaded executor runs callbacks serially. Multi-threaded execution may run callbacks concurrently, so shared mutable state may require synchronisation.

## 6. QoS — CORE overview
Quality of Service controls delivery behaviour such as reliability, durability, and history depth. Use the default profile for this exercise; understand that publisher/subscriber QoS settings must be compatible.

## 7. Ownership and node lifetime — CORE
ROS 2 entity handles are commonly stored as `rclcpp` smart pointers in the node. The node owns these handles as members. Avoid unmanaged raw ownership.

## 8. OPTIONAL
Callback groups, intra-process communication, custom interfaces, lifecycle nodes, composition, TF2, actions, and advanced QoS tuning. These are valuable but not required to complete this focused package.
