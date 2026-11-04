// Day 07 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=07 SRC=DAY_07/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
//
// Day 7 note: the main assignment is repairing the programs in starter/.
// Those programs check themselves; see IMPLEMENTATION.md.
#include <cmath>
#include <cstddef>
#include <vector>

// ===== Main assignment: debug and diagnose =====
// Done in starter/buggy_telemetry.cpp and starter/racy_stats.cpp. Not tested here.

// ===== Challenge 1: find the first bad sample =====
int first_invalid_reading(const std::vector<double>& values) {
    // TODO: first index outside [0.0, 20.0], or -1.
    return -1;
}

// ===== Challenge 2: rolling average =====
double average_of_last_k(const std::vector<double>& values, std::size_t k) {
    // TODO: average of the last k values; 0.0 if k == 0 or k > values.size().
    return 0.0;
}

// ===== Exam Part A: all values finite =====
bool all_finite(const std::vector<double>& values) {
    // TODO: false if any value is NaN or infinite; true for empty input.
    return true;
}
