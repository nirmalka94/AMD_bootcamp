# AMD C++ Bootcamp — Complete 8-Day Course

A focused, hands-on C++ interview-preparation course for an experienced robotics engineer who wants to strengthen independent implementation, debugging, and technical explanation.

## Course map

| Day | Focus | Main assignment |
|---|---|---|
| 1 | C++ fundamentals | Robot telemetry analyser |
| 2 | Classes, lifetime, ownership | Distance sensor model |
| 3 | STL and data structures | Robot fleet state manager |
| 4 | DSA and interview patterns | Sensor event processor |
| 5 | Modern C++ and concurrency | Thread-safe sensor pipeline |
| 6 | ROS 2 C++ | Robot status node with pub/sub/service |
| 7 | Linux debugging and robotics systems | Diagnose and harden a telemetry pipeline |
| 8 | Interview simulation and consolidation | Timed coding + robotics/C++ mock interview |

Days 1–2 are retained from the approved two-day reference. Days 3–8 follow the same format and depth.

## How to study
- Work through one day at a time. Do not read all eight theory files in advance.
- Attempt the starter tasks without AI assistance first.
- Use compiler errors, small tests, and a debugger before asking for help.
- Open instructor solutions only after a genuine attempt.
- Explain your implementation aloud after each main assignment.
- CORE material is required; OPTIONAL and REFERENCE material should not delay completion.

## Daily workload
Target 5–6 focused hours including breaks. The schedule is a guide, not a quota. If you are stuck, reduce scope and complete the core learning outcome rather than rushing.

## Build baseline
Days 1–5 and most Day 7 exercises use standard C++17 and can be built with `g++`.
Day 6 requires an installed ROS 2 environment (Humble or Jazzy) and a sourced workspace.
Day 8 uses the exercises and review material from previous days.

## Folder convention
Each day contains:
- `README.md`
- `THEORY.md`
- `IMPLEMENTATION.md`
- `CHALLENGES.md` (exactly two mandatory challenges)
- `EXAM.md` (45–60 minutes)
- `REVIEW.md`
- `starter/`
- `my_solutions.cpp` (your file for the assignment, both challenges, and the exam coding task)
- `tests/` (automated checks for the assignment, challenges, and exam coding task)
- `instructor_solutions/`, including `ANSWERS.md` with model answers for the exam's debugging and technical questions

Instructor solutions are provided for learning review. Do not open them before attempting the work.

## Checking your work
There are two kinds of test run. As a learner you only need the first.

### 1. Testing your own implementation (learners)
- **Main assignment:** each starter program ends with self-checks. Run it and read the last line, for example `Day 3 fleet manager: 12/12 checks passed`. Every `FAIL` line names a check that is still wrong.
- **Challenges and exam coding task:** write them in that day's `my_solutions.cpp`. It already contains a stub, marked `TODO`, for every function the tests call. Copy your finished main-assignment code into its section too. Then run, from the course root:
  ```bash
  make test DAY=04 SRC=DAY_04/my_solutions.cpp
  ```
  Stubs you have not finished simply report `FAIL`; the rest of the checks still run. Keep every name and signature, and do not add `main()`.

Both kinds of check build with warnings on. Until you implement a TODO function, the compiler warns that its parameter is unused; that warning is expected. `make test` also uses AddressSanitizer and UndefinedBehaviorSanitizer, so memory errors are reported even when the output looks right. Read `DAY_XX/tests/tests.cpp` only after your attempt; it contains the expected answers.

On Day 6 only the portable status logic is tested. On Day 7, `make test` covers the challenges and exam; the main assignment is checked by the repaired starter programs themselves.

### 2. Testing the instructor solutions (course maintainers)
These commands verify the course itself, not your work:
- `make test DAY=04` (without `SRC`) runs one day's tests against `instructor_solutions/`.
- `make check` compiles every starter and every `my_solutions.cpp` template, and runs all reference solutions under the sanitizers.
- `make ros` (with ROS 2 sourced) builds the Day 6 starter package and the reference solution package.

A passing `make check` says nothing about your own code; use `make test ... SRC=...` for that.
