#include <iostream>
#include <vector>
#include <string>

#include "../../common/check.hpp"

double minimum_reading(const std::vector<double>& readings) {
    // TODO: implement. Return 0.0 for empty input.
    return 0.0;
}

double maximum_reading(const std::vector<double>& readings) {
    // TODO: implement. Return 0.0 for empty input.
    return 0.0;
}

double average_reading(const std::vector<double>& readings) {
    // TODO: implement. Return 0.0 for empty input.
    return 0.0;
}

std::string classify_robot(double minimum_distance) {
    // TODO: implement CRITICAL / CAUTION / CLEAR thresholds.
    return "UNKNOWN";
}

int main() {
    const std::vector<double> readings{0.72, 1.42, 0.18, 0.55, 0.64};

    if (readings.empty()) {
        std::cout << "No sensor readings available\n";
        return 0;
    }

    const double minimum = minimum_reading(readings);
    const double maximum = maximum_reading(readings);
    const double average = average_reading(readings);

    std::cout << "Minimum: " << minimum << " m\n";
    std::cout << "Maximum: " << maximum << " m\n";
    std::cout << "Average: " << average << " m\n";
    std::cout << "Robot status: " << classify_robot(minimum) << '\n';

    // Self-checks: each failing line is reported until the function is correct.
    CHECK_NEAR(minimum, 0.18, 1e-9);
    CHECK_NEAR(maximum, 1.42, 1e-9);
    CHECK_NEAR(average, 0.702, 1e-9);
    CHECK(average_reading({}) == 0.0);
    CHECK(classify_robot(0.19) == "CRITICAL");
    CHECK(classify_robot(0.20) == "CAUTION");
    CHECK(classify_robot(0.49) == "CAUTION");
    CHECK(classify_robot(0.50) == "CLEAR");
    return bootcamp::report("Day 1 telemetry analyser");
}
