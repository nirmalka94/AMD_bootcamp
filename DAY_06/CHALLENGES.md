# Day 6 Mandatory Challenges

## Challenge 1 — Add a battery warning (25 minutes)
Subscribe to `/robot/battery` (`std_msgs/msg/Int32`) and include the latest battery percentage in the published status, for example `RUNNING | battery 15% LOW`. Do not add a custom message interface.

Test it with:
```bash
ros2 topic pub --once /robot/battery std_msgs/msg/Int32 "{data: 15}"
```

Acceptance:
- Values outside `[0, 100]` are ignored and the previous value is kept.
- Values below 20 are reported as `LOW`.
- Before the first valid reading, the status says the battery is unknown.
- Explain which callback updates the value and which callback reads it.

## Challenge 2 — Add a command counter (25 minutes)
Count valid START and STOP commands and include the counts in the status output, for example `RUNNING | battery 15% LOW | start 1 stop 0`.

Acceptance:
- Unknown commands do not increment either counter.
- Counts are correct after a sequence of commands.
- If you use a multi-threaded executor, protect shared state. With the single-threaded executor used here, explain the serial callback assumption.

## Without ROS 2
Add the same features to `StatusLogic` in `starter/portable_status_logic.cpp`: an `on_battery(int)` callback, the two counters, and the extended status text in `on_timer`. Update the expected messages in `main` to match.

## Optional
Read about callback groups and actions. Do not implement a full action server/client as part of this day.
