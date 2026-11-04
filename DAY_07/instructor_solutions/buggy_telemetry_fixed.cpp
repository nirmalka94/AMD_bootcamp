// Reference repair of starter/buggy_telemetry.cpp. Each fix names the defect it removes.
// Run from DAY_07/starter so the limits file is found.
#include <cerrno>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../../common/check.hpp"

struct Limits {
    double min_m{0.0};
    double max_m{20.0};
    bool loaded{false};
};

// Optional defect 6 (Part F, found with strace): the file name was misspelt, and the error hid
// both the path and the reason. The message now says what failed and why.
// A file that cannot be parsed is rejected instead of being half-applied.
Limits load_limits(const std::string& path) {
    Limits limits;
    std::ifstream in(path);
    if (!in) {
        // On Linux the failed open() leaves errno set; the standard does not promise this.
        std::cerr << "Could not open limits file '" << path << "': "
                  << std::strerror(errno) << "; using defaults\n";
        return limits;
    }
    Limits parsed;
    if (!(in >> parsed.min_m >> parsed.max_m) || parsed.min_m >= parsed.max_m) {
        std::cerr << "Invalid limits in '" << path << "'; using defaults\n";
        return limits;
    }
    parsed.loaded = true;
    return parsed;
}

// Defect 1: empty input divided by zero and returned NaN.
double average(const std::vector<double>& samples) {
    if (samples.empty()) return 0.0;
    double total = 0.0;
    for (double value : samples) total += value;
    return total / static_cast<double>(samples.size());
}

// Defect 2: the loop read samples[i + 1] on its last iteration (heap-buffer-overflow).
double max_jump(const std::vector<double>& samples) {
    double largest = 0.0;
    for (std::size_t i = 1; i < samples.size(); ++i) {
        const double jump = std::fabs(samples[i] - samples[i - 1]);
        if (jump > largest) largest = jump;
    }
    return largest;
}

// Defect 3: `previous` referred into the vector, and push_back reallocated it
// (heap-use-after-free). back() on an empty history was also undefined.
double record(std::vector<double>& history, double value) {
    if (history.empty()) {
        history.push_back(value);
        return 0.0;
    }
    const double previous = history.back();  // copy, not reference
    history.push_back(value);
    return value - previous;
}

// Defect 4: the limits were never applied.
bool update_sensor(double& current, double next_value, const Limits& limits) {
    if (next_value < limits.min_m || next_value > limits.max_m) return false;
    current = next_value;
    return true;
}

int main() {
    const Limits limits = load_limits("telemetry_limits.conf");
    std::cout << "Limits: [" << limits.min_m << ", " << limits.max_m << "] m\n";

    const std::vector<double> samples{0.5, 0.8, 1.2};
    std::cout << "Average: " << average(samples) << " m\n";
    std::cout << "Max jump: " << max_jump(samples) << " m\n";

    std::vector<double> history{1.0, 1.5};
    std::cout << "Change: " << record(history, 2.25) << " m\n";

    double sensor_value = 0.0;
    const bool accepted = update_sensor(sensor_value, 25.0, limits);
    std::cout << "Update accepted: " << std::boolalpha << accepted
              << ", value=" << sensor_value << '\n';

    // The limits file is the optional Part F; these checks pass with or without it.
    if (!limits.loaded) std::cout << "Note: limits file not loaded (optional Part F)\n";
    CHECK_NEAR(average(samples), 0.8333333, 1e-6);
    CHECK(average({}) == 0.0);
    CHECK_NEAR(max_jump(samples), 0.4, 1e-9);
    CHECK(max_jump({}) == 0.0);
    CHECK(max_jump({3.0}) == 0.0);
    CHECK(history.size() == 3);
    std::vector<double> empty_history;
    CHECK(record(empty_history, 4.0) == 0.0);
    CHECK(!accepted);
    CHECK(sensor_value == 0.0);
    CHECK(!update_sensor(sensor_value, -0.5, limits));
    CHECK(update_sensor(sensor_value, 3.0, limits) && sensor_value == 3.0);
    return bootcamp::report("Day 7 telemetry");
}
