// Day 7 tests: both challenges and the exam coding task.
// The repaired assignment programs check themselves; `make check` runs them under sanitizers.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/challenges.cpp"
#endif
#include SOLUTION_FILE

#include <limits>
#include <vector>

#include "../../common/check.hpp"

int main() {
    // Challenge 1
    CHECK(first_invalid_reading({}) == -1);
    CHECK(first_invalid_reading({1.0, 2.0, 25.0, -1.0}) == 2);
    CHECK(first_invalid_reading({0.0, 20.0}) == -1);
    CHECK(first_invalid_reading({-0.1}) == 0);

    // Challenge 2
    CHECK_NEAR(average_of_last_k({1, 2, 3, 4}, 2), 3.5, 1e-9);
    CHECK_NEAR(average_of_last_k({1, 2, 3, 4}, 4), 2.5, 1e-9);
    CHECK(average_of_last_k({}, 1) == 0.0);
    CHECK(average_of_last_k({1, 2}, 0) == 0.0);
    CHECK(average_of_last_k({1, 2}, 3) == 0.0);

    // Exam Part A
    const double inf = std::numeric_limits<double>::infinity();
    const double nan = std::numeric_limits<double>::quiet_NaN();
    CHECK(all_finite({}));
    CHECK(all_finite({0.0, -3.5, 1e300}));
    CHECK(!all_finite({1.0, nan}));
    CHECK(!all_finite({inf}));
    CHECK(!all_finite({-inf, 2.0}));

    return bootcamp::report("Day 7 tests");
}
