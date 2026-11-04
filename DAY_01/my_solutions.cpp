// Day 01 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=01 SRC=DAY_01/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
#include <cmath>
#include <string>
#include <vector>

// ===== Main assignment: telemetry analyser =====
// TODO: copy your finished functions from starter/telemetry_analyser.cpp.

double minimum_reading(const std::vector<double>& readings) {
    // TODO: smallest value; 0.0 for empty input.
    return 0.0;
}

double maximum_reading(const std::vector<double>& readings) {
    // TODO: largest value; 0.0 for empty input.
    return 0.0;
}

double average_reading(const std::vector<double>& readings) {
    // TODO: mean value; 0.0 for empty input.
    return 0.0;
}

std::string classify_robot(double minimum_distance) {
    // TODO: CRITICAL < 0.20, CAUTION < 0.50, otherwise CLEAR.
    return "UNKNOWN";
}

// ===== Challenge 1: count close obstacles =====
int count_close_readings(const std::vector<double>& readings, double threshold) {
    // TODO: count readings strictly below threshold.
    return 0;
}

// ===== Challenge 2: convert and filter =====
std::vector<double> valid_readings(const std::vector<double>& readings) {
    // TODO: return readings in [0.0, 10.0]; do not modify the input.
    return {};
}

// ===== Exam Part A: root mean square =====
double calculate_rms(const std::vector<double>& values) {
    // TODO: sqrt(mean of squares); 0.0 for empty input.
    return 0.0;
}

// ===== Exam Part B: your corrected average() =====
double average(const std::vector<double>& values) {
    // TODO: paste your fixed version of the exam's average().
    return 0.0;
}
