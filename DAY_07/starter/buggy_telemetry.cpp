// Day 7 telemetry processor. It compiles, but it is not correct.
// Run it from this directory; it tries to read a limits file here.
#include <cmath>
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

// Reads "<min_m> <max_m>" from a text file. Falls back to defaults on failure.
Limits load_limits(const std::string& path) {
    Limits limits;
    std::ifstream in(path);
    if (!in) {
        std::cerr << "Could not load limits, using defaults\n";
        return limits;
    }
    in >> limits.min_m >> limits.max_m;
    limits.loaded = true;
    return limits;
}

double average(const std::vector<double>& samples) {
    double total = 0.0;
    for (double value : samples) total += value;
    return total / samples.size();
}

// Largest absolute change between consecutive samples.
double max_jump(const std::vector<double>& samples) {
    double largest = 0.0;
    for (std::size_t i = 0; i < samples.size(); ++i) {
        const double jump = std::fabs(samples[i + 1] - samples[i]);
        if (jump > largest) largest = jump;
    }
    return largest;
}

// Appends a sample to the history and returns the change from the previous sample.
double record(std::vector<double>& history, double value) {
    const double& previous = history.back();
    history.push_back(value);
    return value - previous;
}

// Stores next_value in current if it lies within the limits.
bool update_sensor(double& current, double next_value, const Limits& limits) {
    current = next_value;
    return true;
}

int main() {
    const Limits limits = load_limits("telemetry_limit.conf");
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
