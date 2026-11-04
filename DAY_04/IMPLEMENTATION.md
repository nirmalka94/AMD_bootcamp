# Day 4 Implementation — Sensor Event Processor

## Goal
Complete `starter/sensor_event_processor.cpp`.

## Step 1 — `has_pair_with_sum`
Return true if two distinct elements sum to the target. Use an unordered set to store values already seen. Aim for O(n) average time.

## Step 2 — `max_window_sum`
Given a vector and window size `k`, return the maximum sum of any contiguous window of exactly `k` elements. Return 0 if `k == 0` or `k > values.size()`.

Use a sliding window: calculate the first window once, then subtract the outgoing value and add the incoming value.

## Step 3 — `valid_delimiters`
Validate `()`, `[]`, and `{}` using a stack. Non-delimiter characters may be ignored. A closing delimiter must match the most recent unmatched opening delimiter.

## Step 4 — Complexity notes
For each function, write one line describing time and extra space complexity.

## Build
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic sensor_event_processor.cpp -o event_processor
./event_processor
```

## Expected behaviour
The supplied `main()` prints a pair sum, a maximum window, and a delimiter result, then runs self-checks that include empty and boundary cases. The final line should read `Day 4 sensor event processor: 14/14 checks passed`.
