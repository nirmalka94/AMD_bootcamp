#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "../../common/check.hpp"

class SensorQueue {
public:
    explicit SensorQueue(std::size_t capacity) : capacity_(capacity) {}

    bool push(int value) {
        // TODO: wait for space or closure; enqueue and notify.
        return false;
    }

    bool pop(int& value) {
        // TODO: wait for data or closure; dequeue and notify.
        return false;
    }

    void close() {
        // TODO: set closed flag under lock and notify all waiters.
    }

private:
    const std::size_t capacity_;
    std::queue<int> queue_;
    std::mutex mutex_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;
    bool closed_{false};
};

int main() {
    SensorQueue queue(4);
    std::vector<int> consumed;

    std::thread producer([&queue] {
        for (int sample = 1; sample <= 10; ++sample) {
            if (!queue.push(sample)) break;
        }
        queue.close();
    });

    std::thread consumer([&queue, &consumed] {
        int sample = 0;
        while (queue.pop(sample)) {
            std::cout << "Consumed sensor sample: " << sample << '\n';
            consumed.push_back(sample);
        }
    });

    producer.join();
    consumer.join();

    // Self-checks: each failing line is reported until the queue is correct.
    CHECK((consumed == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));

    SensorQueue drained(2);
    CHECK(drained.push(7));
    drained.close();
    int value = 0;
    CHECK(drained.pop(value) && value == 7);
    CHECK(!drained.pop(value));
    CHECK(!drained.push(8));
    return bootcamp::report("Day 5 sensor queue");
}
