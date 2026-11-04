# Day 7 Implementation — Debug and Diagnose

You have two faulty programs in `starter/`:
- `buggy_telemetry.cpp`: a single-threaded telemetry processor with **four** mandatory defects (memory and logic), plus one optional configuration fault;
- `racy_stats.cpp`: statistics shared by two sensor threads, with **one** defect.

You are told the symptoms, not where the defects are. Finding them is the exercise. Both programs end with self-checks; you are done when every check passes **and** the sanitizer builds report nothing.

**Mandatory:** Parts A–E (memory debugging and concurrency debugging) and Part G. **Optional:** Part F (`strace` configuration investigation). Do it only if you have time left; skipping it does not affect any self-check.

Work from `DAY_07/starter`.

## Part A — Reproduce (15 minutes)
```bash
cd DAY_07/starter
g++ -std=c++17 -Wall -Wextra -Wpedantic -g buggy_telemetry.cpp -o telemetry
./telemetry
```
Write down:
- every compiler warning, and what each one could mean;
- every failed check and every suspicious printed value.

Do not edit anything yet. One warning already points at a defect.

## Part B — Memory errors with AddressSanitizer (30 minutes)
```bash
g++ -std=c++17 -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer buggy_telemetry.cpp -o telemetry_san
./telemetry_san
```
ASan stops at the first error it finds. For each report:
1. Read the error type (for example `heap-buffer-overflow` or `heap-use-after-free`) and the first stack frame in **your** code.
2. Explain the root cause in one sentence before you change anything.
3. Make the smallest fix, rebuild, and rerun.

Expect two different ASan reports in sequence. The second is a lifetime bug: ask what `push_back` can do to the vector's storage.

## Part C — Inspect state with GDB (15 minutes)
On the unfixed build, set a breakpoint in the loop that ASan reported first:
```bash
gdb ./telemetry
(gdb) break max_jump
(gdb) run
(gdb) next          # repeat until inside the loop
(gdb) print i
(gdb) print samples.size()
(gdb) backtrace
```
Explain what value of `i` makes the access invalid, and why the plain build did not crash.

## Part D — Logic defects (15 minutes)
The remaining failed checks are not memory errors, so no sanitizer will find them. Use the failed check lines and the compiler warning from Part A. Fix:
- the empty-input behaviour of `average`;
- the update that ignores the configured limits.

## Part E — A data race with ThreadSanitizer (20 minutes)
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -pthread racy_stats.cpp -o racy_stats
./racy_stats                       # run it several times
g++ -std=c++17 -g -O1 -fsanitize=thread -pthread racy_stats.cpp -o racy_stats_tsan
./racy_stats_tsan
```
If ThreadSanitizer stops with `FATAL: ThreadSanitizer: unexpected memory mapping`, your kernel's address-space randomisation is too high for this GCC version. Run it as `setarch "$(uname -m)" -R ./racy_stats_tsan`.

Read the two stack traces in each report: they show the conflicting accesses. Fix the class so both members are updated consistently, then confirm that TSan is silent and the checks pass on every run. Explain why the plain build gives different results from run to run.

## Part F — OPTIONAL extension: find a configuration fault with `strace` (15 minutes)
Skip this part if you are short of time. After Parts B–D the program still prints `Could not load limits, using defaults` and `Note: limits file not loaded`, even though `telemetry_limits.conf` is in the directory. It runs on default limits instead of the configured `[0.05, 15.0]` m.
```bash
strace -e trace=openat ./telemetry
```
Find the `openat` call for the limits file and its result. Then:
1. fix the root cause;
2. harden `load_limits` so a future failure reports the **path** and the **reason** (`std::strerror(errno)`), and rejects a file it cannot parse.

## Part G — Robotics performance scenario (25 minutes)
A perception node normally processes 25 frames/s. When a language model starts generating, perception falls to 8–9 frames/s and the display becomes jittery.

Write a one-page investigation plan:
1. List observations separately from hypotheses.
2. Identify at least four measurements, for example per-stage latency, CPU per process and thread, memory bandwidth or allocation rate, queue depth, and frame age.
3. Propose two experiments that isolate CPU contention from I/O or display contention.
4. Explain what evidence would confirm or reject each hypothesis.
5. Recommend one short-term mitigation and one longer-term architectural improvement.

Do not assume that adding threads automatically improves performance.

## Acceptance criteria
- `./telemetry` reports `11/11 checks passed` when run from `DAY_07/starter`.
- `./telemetry_san` runs with no sanitizer report.
- `./racy_stats` reports `2/2 checks passed` on every run, and `./racy_stats_tsan` reports no data race.
- For each of the five mandatory defects you can state the symptom, the tool that exposed it, and the root cause.
- Optional Part F: the `Note: limits file not loaded` line no longer appears, and the program prints `Limits: [0.05, 15] m`.
