#include <cmath>
#include <cstddef>
#include <vector>

// Challenge 1 reference implementation.
int first_invalid_reading(const std::vector<double>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (values[i] < 0.0 || values[i] > 20.0) return static_cast<int>(i);
    }
    return -1;
}

// Challenge 2 reference implementation: O(k) per query.
// For repeated queries, keep a running sum over a fixed-size ring buffer
// (add the new value, subtract the one that falls out) for O(1) per update.
double average_of_last_k(const std::vector<double>& values, std::size_t k) {
    if (k == 0 || k > values.size()) return 0.0;
    double total = 0.0;
    for (std::size_t i = values.size() - k; i < values.size(); ++i) total += values[i];
    return total / static_cast<double>(k);
}

// Exam reference implementation. std::isfinite is false for NaN and both infinities.
bool all_finite(const std::vector<double>& values) {
    for (double value : values) {
        if (!std::isfinite(value)) return false;
    }
    return true;
}
