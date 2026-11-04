# Day 3 Implementation — Fleet State Manager

## Goal
Complete `starter/fleet_manager.cpp`.

The manager stores records with `id`, `name`, `battery_percent`, and `online`.

## Step 1 — Inspect the data model
`RobotState` is supplied. `FleetManager` owns a vector of states. The assignment intentionally uses a vector so you practise iteration and standard algorithms.

## Step 2 — Implement `add_robot`
Reject an empty ID and duplicate IDs. Return `true` only when a new record is added.

## Step 3 — Implement `update_battery`
Find the robot by ID. Return `false` if it does not exist or the battery value is outside `[0, 100]`. Otherwise update the value.

## Step 4 — Implement `find_robot`
Return a pointer to the matching record, or `nullptr` if not found. Provide both mutable and const overloads if you are comfortable; one const overload is sufficient for CORE.

The returned pointer refers into `robots_`. It is valid only until the fleet is next modified: a later `add_robot` can reallocate the vector and leave the pointer dangling. See THEORY section 6, and be ready to explain this.

## Step 5 — Implement `low_battery_robots`
Use `std::copy_if` or `std::find_if`/a loop to return records whose battery is strictly below the threshold.

## Step 6 — Implement `sorted_ids`
Collect IDs and sort them with `std::sort`.

## Step 7 — Build
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic fleet_manager.cpp -o fleet_manager
./fleet_manager
```

## Expected behaviour
The sample main adds three robots, updates one battery, rejects an invalid update, and prints the low-battery IDs and all IDs in sorted order. It then runs self-checks; the final line should read `Day 3 fleet manager: 12/12 checks passed`.

## Explain aloud
Why is `unordered_map` often a better fit for ID lookup at scale, while a vector can still be a reasonable choice for a small fleet?
