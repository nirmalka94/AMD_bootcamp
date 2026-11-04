# Day 6 Implementation — Robot Status Node

## Goal
Complete `starter/robot_status_node/src/robot_status_node.cpp`.

The package:
- publishes `std_msgs/msg/String` on `/robot/status` every 500 ms;
- subscribes to `/robot/command` (`std_msgs/msg/String`);
- exposes `/robot/enable_status` (`std_srvs/srv/SetBool`).

## Step 1 — Inspect package metadata
Review `package.xml` and `CMakeLists.txt`. They declare `rclcpp`, `std_msgs`, and `std_srvs`.

## Step 2 — Create publisher
In the node constructor, create a publisher with queue depth 10.

## Step 3 — Create subscription
Subscribe to `/robot/command`. In the callback:
- `"STOP"` sets `command_state_` to `"STOP"`;
- `"START"` sets it to `"RUNNING"`;
- any other input sets it to `"UNKNOWN"`.

## Step 4 — Create timer
Every 500 ms, publish a message containing the current command state if publishing is enabled.

## Step 5 — Create service
The SetBool service toggles `publishing_enabled_`. Set the response success flag and include a short explanatory message.

## Step 6 — Build and run
From a ROS 2-sourced terminal:
```bash
mkdir -p ~/robot_ws/src
cp -r robot_status_node ~/robot_ws/src/
cd ~/robot_ws
colcon build --packages-select robot_status_node
source install/setup.bash
ros2 run robot_status_node robot_status_node
```

In another terminal:
```bash
source ~/robot_ws/install/setup.bash
ros2 topic pub --once /robot/command std_msgs/msg/String "{data: START}"
ros2 service call /robot/enable_status std_srvs/srv/SetBool "{data: false}"
ros2 topic echo /robot/status
```

## Expected behaviour
- With publishing enabled, status messages appear every 500 ms.
- `STOP` and `START` change the published state.
- Calling the service with `data: false` stops periodic publication.
- Calling it with `data: true` resumes publication.

## No ROS 2?
Complete `starter/portable_status_logic.cpp` instead (see `starter/README.md`). The final line should read `Day 6 portable status logic: 3/3 checks passed`.

## Explain aloud
What does the executor do? Why should a subscription callback avoid lengthy blocking work?
