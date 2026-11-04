// Day 05 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=05 SRC=DAY_05/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
#include <condition_variable>
#include <cstddef>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

// ===== Main assignment: bounded sensor queue =====
// TODO: copy your finished class from starter/sensor_queue.cpp.
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

// ===== Challenge 1: thread-safe counter =====
class ThreadSafeCounter {
public:
    void increment() {
        // TODO: safe to call from many threads at once.
    }

    long value() const {
        // TODO
        return 0;
    }

private:
    // TODO: add the members you need.
};

// ===== Challenge 2: move-only ownership =====
std::unique_ptr<int> take_and_return(std::unique_ptr<int> value) {
    // TODO: return the pointer you were given.
    return nullptr;
}

// ===== Exam Part A: two threads, combined total =====
int combined_total() {
    // TODO: two threads, each increments its own counter 10,000 times; join both; return the sum.
    return 0;
}
