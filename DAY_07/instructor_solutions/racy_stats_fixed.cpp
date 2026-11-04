// Reference repair of starter/racy_stats.cpp.
// Defect 5: both threads updated count_ and total_ without synchronisation (data race).
// One mutex guards both members so a reader never sees a count without its total.
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>

#include "../../common/check.hpp"

class SampleStats {
public:
    void add(double value) {
        std::lock_guard<std::mutex> lock(mutex_);
        ++count_;
        total_ += value;
    }

    std::size_t count() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return count_;
    }

    double mean() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return count_ == 0 ? 0.0 : total_ / static_cast<double>(count_);
    }

private:
    mutable std::mutex mutex_;
    std::size_t count_{0};
    double total_{0.0};
};

int main() {
    SampleStats stats;

    std::thread front_sensor([&stats] {
        for (int i = 0; i < 50000; ++i) stats.add(1.0);
    });
    std::thread rear_sensor([&stats] {
        for (int i = 0; i < 50000; ++i) stats.add(3.0);
    });
    front_sensor.join();
    rear_sensor.join();

    std::cout << "Samples: " << stats.count() << ", mean: " << stats.mean() << '\n';
    CHECK(stats.count() == 100000);
    CHECK_NEAR(stats.mean(), 2.0, 1e-9);
    return bootcamp::report("Day 7 sample stats");
}
