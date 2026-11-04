# Day 7 — Reference Solutions and Exam Model Answers

## Main assignment: five mandatory defects and one optional fault
| # | File | Symptom | Exposed by | Root cause and fix |
|---|---|---|---|---|
| 1 | `buggy_telemetry.cpp` | `average({})` check fails (result is NaN) | Failed self-check | Divides by `size()` when it is 0. Return `0.0` for empty input. |
| 2 | `buggy_telemetry.cpp` | Wrong max jump; `heap-buffer-overflow` in `max_jump` | ASan, then GDB (`i == size() - 1`) | Reads `samples[i + 1]` on the last iteration. Loop from `i = 1` and compare with `i - 1`. |
| 3 | `buggy_telemetry.cpp` | Garbage "Change" value; `heap-use-after-free` in `record` | ASan | `previous` is a reference into the vector, and `push_back` reallocates. Copy the value first, and handle an empty history. |
| 4 | `buggy_telemetry.cpp` | Invalid updates accepted | `-Wunused-parameter` on `limits`, failed checks | The limits are never applied. Reject values outside `[min_m, max_m]`. |
| 5 | `racy_stats.cpp` | Count and mean differ from run to run | ThreadSanitizer | Two threads update `count_` and `total_` without synchronisation. Guard both with one mutex. |
| 6 (optional) | `buggy_telemetry.cpp` | `Note: limits file not loaded`; vague error message | `strace -e trace=openat` shows `telemetry_limit.conf` → `ENOENT` | The file name is misspelt. Fix it, and report the path and `strerror(errno)` on failure; reject an unparsable file. |

The plain build of defect 2 usually does not crash: reading 8 bytes past a small heap block lands in memory the process owns, so the read silently returns garbage. This is why undefined behaviour cannot be "tested away" without sanitizers.

Reference repairs: `buggy_telemetry_fixed.cpp` and `racy_stats_fixed.cpp`. Challenge and exam code: `challenges.cpp`.

## Exam Part A — Coding
See `all_finite` in `challenges.cpp`. `std::isfinite` rejects NaN, `+inf` and `-inf` in one call. Comparing with `==` does not work, because NaN compares unequal to everything, itself included.

## Exam Part B — Debugging and diagnosis
Full marks for any five sensible items that include at least one tool, plus the reason for reproducing on the target. For example:
1. **The exact failure signature**: the signal (SIGSEGV, SIGABRT, or killed by the OOM killer) from the logs and `dmesg`/`journalctl`.
2. **A core dump and backtrace on the target** (`ulimit -c unlimited` or `coredumpctl`, then `gdb ./app core`), from a build with `-g`.
3. **Environment differences**: CPU architecture, core count, compiler and library versions (`ldd`, package versions), build flags, kernel, configuration, and real sensor rates.
4. **A sanitizer build** (ASan/UBSan, or TSan if the failure is intermittent and timing-dependent) run on the target or on recorded data such as a rosbag.
5. **Resource trends up to the crash**: memory growth (`top` RSS, `free`), CPU load, disk space (`df`), open file descriptors.

**Why the target matters:** timing, core count, architecture details (alignment, `char` signedness, memory ordering), library versions and real input rates all change which bugs appear. A fix is only verified where the failure happens.

## Part C — Technical questions
1. **It adds symbol and line information**, so backtraces show function names and lines and GDB can show source and variables. It does not change the generated code's behaviour.
2. **Memory errors at run time**: heap, stack and global buffer overflows, use-after-free, use-after-return, double free, and leaks (through LeakSanitizer).
3. **The chain of active function calls at a point in time**, such as the crash, listed innermost frame first. It shows how execution got there.
4. **To inspect a live or crashed program's state**: breakpoints, stepping, printing variables, watchpoints, all threads' stacks when attached to a hung process, and post-mortem analysis of a core dump.
5. **The shared libraries a binary needs and which file each one resolves to**, or `not found`.
6. **The kernel log**: driver and device errors (for example a USB camera disconnecting), OOM-killer activity, segfault reports, and hardware errors.
7. **Throughput is items completed per unit time (frames/s); latency is the time for one item from input to output (ms).** Pipelining can raise throughput while latency stays high.
8. **The producer is faster than the consumer, so items pile up in the queue.** Memory grows and each processed item gets older. Bound the queue and choose a drop policy.
9. **A slowdown can come from waiting, not computing**: lock contention, I/O, memory bandwidth, cache misses, throttling, scheduling. Average CPU percentage also hides a single saturated thread.
10. Any one of: **data races, deadlocks, nondeterministic timing and jitter, priority inversion, contention that reduces performance, harder debugging**.
