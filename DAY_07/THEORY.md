# Day 7 Theory — Debugging and Robotics Systems

Legend: **CORE** required; **OPTIONAL** later review.

## 1. Reproduce before patching — CORE
Record the exact input, command, environment, and observed failure. Reduce the failure to the smallest reproducible case. Avoid changing several things at once.

## 2. Compiler diagnostics — CORE
Build with:
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -g app.cpp -o app
```
Warnings often expose suspicious conversions, unused variables, and control-flow mistakes. `-g` includes debug symbols.

## 3. AddressSanitizer and UndefinedBehaviorSanitizer — CORE
For local debugging:
```bash
g++ -std=c++17 -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer app.cpp -o app
./app
```
These tools can detect many memory errors and forms of undefined behaviour. They do not prove the program is correct, and they only see code paths that actually run.

ThreadSanitizer detects data races. It cannot be combined with AddressSanitizer, so use a separate build:
```bash
g++ -std=c++17 -g -O1 -fsanitize=thread -pthread app.cpp -o app_tsan
./app_tsan
```
A race may give correct output on most runs; TSan reports it on a run where the conflicting accesses are not synchronised, even if the output happens to be right. On some newer kernels GCC 11's TSan fails with `unexpected memory mapping`; run it under `setarch "$(uname -m)" -R` to disable address randomisation for that process.

## 4. GDB — CORE
Useful commands:
- `gdb ./app`
- `break main`
- `run`
- `next`, `step`, `continue`
- `print variable`
- `backtrace`
- `quit`

Use a breakpoint near the first incorrect state, then inspect values and the call stack.

## 5. Linux investigation tools — CORE
- `ps`, `top`: process state and CPU usage.
- `free`, `vmstat`: memory and system activity.
- `df`, `du`: filesystem capacity and usage.
- `dmesg`: kernel and device messages.
- `ldd`: dynamic library dependencies.
- `strace`: system calls and failures at the process/kernel boundary.

Choose the tool based on the symptom. Do not run every tool indiscriminately.

`strace` is often the fastest way to explain "it cannot find its configuration" or "it hangs" (used in the optional Part F):
```bash
strace -e trace=openat ./app      # which files it tries to open, and the errno for each
strace -f -p <pid>                # what a running process (and its threads) is blocked in
```

## 6. Robotics pipeline reasoning — CORE
For a sensor → preprocessing → perception → planning → control pipeline, reason about:
- input rate and processing rate;
- queue growth and stale data;
- copy volume and memory allocation;
- callback blocking and thread contention;
- CPU saturation and scheduling;
- timestamp consistency and end-to-end latency.

A high CPU percentage is an observation, not a root cause. Measure stage timing and queue depth before proposing optimisation.

## 7. Performance and concurrency — CORE overview
Distinguish throughput (items/second) from latency (time per item). A system can have acceptable average throughput but poor tail latency. Parallel execution can improve throughput but may increase contention and jitter.

## 8. OPTIONAL
Perf, heap profiling, core dumps, flame graphs, real-time scheduling, lock-free queues, cache-line effects, and kernel tracing are valuable follow-up topics.
