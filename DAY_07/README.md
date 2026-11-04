# Day 7 — Linux Debugging and Robotics Systems Reasoning

**Theme:** Diagnose a faulty sensor-processing component and explain how you would investigate a performance regression on a robot.

## Learning outcomes
- Compile with warnings and sanitizers.
- Use a debugger to inspect state and call stacks.
- Recognise out-of-bounds access, lifetime errors, and race-condition symptoms.
- Use basic Linux tools (`ps`, `top`, `free`, `df`, `dmesg`, `ldd`, `strace`) appropriately.
- Explain a robotics software data path and identify likely CPU, memory, and latency bottlenecks.

## Main assignment
Find and repair five planted defects in `starter/buggy_telemetry.cpp` and `starter/racy_stats.cpp` using compiler warnings, AddressSanitizer, GDB, and ThreadSanitizer. If time remains, an optional extension uses `strace` to find a configuration fault. Then write a short investigation plan for the supplied performance scenario. See `IMPLEMENTATION.md`.

## Schedule (about 5.5 focused hours)
| Block | Duration | Activity |
|---|---:|---|
| 1 | 40 min | Debugging theory and tool selection |
| 2 | 135 min | Main assignment: Parts A–E and G (120 min), optional Part F (15 min) |
| 3 | 15 min | Break |
| 4 | 55 min | Two challenges |
| 5 | 50 min | Cumulative exam |
| 6 | 15 min | Review |

## Completion criteria
- All five mandatory defects are fixed, every self-check passes, and the ASan and TSan builds are silent.
- You can explain the root cause, not only the patch.
- You can select a suitable Linux tool for a stated symptom.
- Your diagnosis separates observation, hypothesis, experiment, and conclusion.
