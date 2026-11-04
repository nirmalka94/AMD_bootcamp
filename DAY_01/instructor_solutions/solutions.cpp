#include <cmath>
#include <string>
#include <vector>

double minimum_reading(const std::vector<double>& readings) {
    if (readings.empty()) return 0.0;
    double result = readings.front();
    for (double value : readings) {
        if (value < result) result = value;
    }
    return result;
}

double maximum_reading(const std::vector<double>& readings) {
    if (readings.empty()) return 0.0;
    double result = readings.front();
    for (double value : readings) {
        if (value > result) result = value;
    }
    return result;
}

double average_reading(const std::vector<double>& readings) {
    if (readings.empty()) return 0.0;
    double total = 0.0;
    for (double value : readings) total += value;
    return total / static_cast<double>(readings.size());
}

std::string classify_robot(double minimum_distance) {
    if (minimum_distance < 0.20) return "CRITICAL";
    if (minimum_distance < 0.50) return "CAUTION";
    return "CLEAR";
}

int count_close_readings(const std::vector<double>& readings, double threshold) {
    int count = 0;
    for (double value : readings) {
        if (value < threshold) ++count;
    }
    return count;
}

std::vector<double> valid_readings(const std::vector<double>& readings) {
    std::vector<double> result;
    for (double value : readings) {
        if (value >= 0.0 && value <= 10.0) result.push_back(value);
    }
    return result;
}

double calculate_rms(const std::vector<double>& values) {
    if (values.empty()) return 0.0;
    double sum_squares = 0.0;
    for (double value : values) sum_squares += value * value;
    return std::sqrt(sum_squares / static_cast<double>(values.size()));
}

// Exam Part B reference fix: range-for removes the out-of-bounds index,
// and the guard avoids dividing by zero for empty input.
double average(const std::vector<double>& values) {
    if (values.empty()) return 0.0;
    double total = 0.0;
    for (double value : values) total += value;
    return total / static_cast<double>(values.size());
}
