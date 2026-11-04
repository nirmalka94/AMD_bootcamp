// Day 1 tests: main assignment, both challenges, and the exam coding tasks.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/solutions.cpp"
#endif
#include SOLUTION_FILE

#include <string>
#include <vector>

#include "../../common/check.hpp"

int main() {
    const std::vector<double> readings{0.72, 1.42, 0.18, 0.55, 0.64};

    // Main assignment
    CHECK_NEAR(minimum_reading(readings), 0.18, 1e-9);
    CHECK_NEAR(maximum_reading(readings), 1.42, 1e-9);
    CHECK_NEAR(average_reading(readings), 0.702, 1e-9);
    CHECK(minimum_reading({}) == 0.0);
    CHECK(maximum_reading({}) == 0.0);
    CHECK(average_reading({}) == 0.0);
    CHECK(minimum_reading({-2.0}) == -2.0);
    CHECK(classify_robot(0.19) == "CRITICAL");
    CHECK(classify_robot(0.20) == "CAUTION");
    CHECK(classify_robot(0.49) == "CAUTION");
    CHECK(classify_robot(0.50) == "CLEAR");

    // Challenge 1
    CHECK(count_close_readings({0.1, 0.4, 0.2, 0.8}, 0.3) == 2);
    CHECK(count_close_readings({}, 0.3) == 0);
    CHECK(count_close_readings({0.3}, 0.3) == 0);

    // Challenge 2
    const std::vector<double> mixed{-1.0, 0.0, 1.5, 10.0, 12.0};
    CHECK((valid_readings(mixed) == std::vector<double>{0.0, 1.5, 10.0}));
    CHECK(mixed.size() == 5);
    CHECK(valid_readings({}).empty());

    // Exam Part A
    CHECK_NEAR(calculate_rms({3.0, 4.0}), 3.5355339, 1e-6);
    CHECK(calculate_rms({}) == 0.0);

    // Exam Part B
    CHECK_NEAR(average({1.0, 2.0, 3.0}), 2.0, 1e-9);
    CHECK(average({}) == 0.0);

    return bootcamp::report("Day 1 tests");
}
