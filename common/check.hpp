// Minimal self-check helpers shared by the starters and the per-day tests.
// CHECK records a failure and keeps going, so one run shows every problem.
#pragma once

#include <cmath>
#include <iostream>

namespace bootcamp {

struct CheckCounts {
    int total{0};
    int failed{0};
};

inline CheckCounts& counts() {
    static CheckCounts value;
    return value;
}

inline void record(bool passed, const char* expression, const char* file, int line) {
    ++counts().total;
    if (!passed) {
        ++counts().failed;
        std::cerr << file << ':' << line << ": FAIL: " << expression << '\n';
    }
}

// Prints a summary and returns a process exit code: 0 when every check passed.
inline int report(const char* name) {
    const CheckCounts& c = counts();
    std::cout << name << ": " << (c.total - c.failed) << '/' << c.total
              << " checks passed\n";
    return c.failed == 0 ? 0 : 1;
}

}  // namespace bootcamp

#define CHECK(expr) ::bootcamp::record(static_cast<bool>(expr), #expr, __FILE__, __LINE__)

#define CHECK_NEAR(actual, expected, tolerance)                            \
    ::bootcamp::record(std::fabs((actual) - (expected)) <= (tolerance),    \
                       #actual " ~= " #expected, __FILE__, __LINE__)
