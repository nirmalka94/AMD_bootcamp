# Course design contract

This eight-day course uses the same learner experience throughout.

## Every day
1. One focused theory chapter.
2. One main assignment with explicit steps.
3. Exactly two mandatory coding challenges.
4. One cumulative exam with:
   - one coding task;
   - one debugging or code-modification task;
   - 8–10 technical questions.
5. One short self-review.

## Scope
- Aim for 5–6 focused hours per day, including breaks.
- Prefer representative implementation over broad topic coverage.
- Keep advanced variants in OPTIONAL or REFERENCE.
- Every task must have acceptance criteria and a realistic time estimate.
- Do not make a learner build a framework when a small class or function demonstrates the concept.

## Learning progression
Day 1 establishes functions, containers, and safe iteration.
Day 2 establishes classes, lifetime, and ownership.
Day 3 applies STL containers and algorithms.
Day 4 practises common interview problem-solving patterns.
Day 5 applies modern C++ ownership and basic concurrency.
Day 6 connects C++ concepts to ROS 2 node design.
Day 7 develops debugging and system-level reasoning.
Day 8 tests independent coding and explanation.

## Standards
- C++17 for portable examples.
- Use `-Wall -Wextra -Wpedantic`.
- Avoid undefined behaviour and unexplained magic constants.
- Prefer RAII and standard library facilities.
- State any environment-specific dependency explicitly.
