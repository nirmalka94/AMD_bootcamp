#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

class SensorQueue {
public:
    explicit SensorQueue(std::size_t capacity) : capacity_(capacity) {}

    bool push(int value) {
        std::unique_lock<std::mutex> lock(mutex_);
        not_full_.wait(lock, [&] { return queue_.size() < capacity_ || closed_; });
        if (closed_) return false;
        queue_.push(value);
        lock.unlock();
        not_empty_.notify_one();
        return true;
    }

    bool pop(int& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        not_empty_.wait(lock, [&] { return !queue_.empty() || closed_; });
        if (queue_.empty()) return false;
        value = queue_.front();
        queue_.pop();
        lock.unlock();
        not_full_.notify_one();
        return true;
    }

    void close() {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            closed_ = true;
        }
        not_empty_.notify_all();
        not_full_.notify_all();
    }

private:
    const std::size_t capacity_;
    std::queue<int> queue_;
    std::mutex mutex_;
    std::condition_variable not_empty_, not_full_;
    bool closed_{false};
};

// Challenge 1 reference implementation.
class ThreadSafeCounter {
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mutex_);
        ++value_;
    }

    long value() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return value_;
    }

private:
    mutable std::mutex mutex_;  // mutable so value() can lock it while staying const
    long value_{0};
};

// Challenge 2 reference implementation: taking by value means the caller must move in.
std::unique_ptr<int> take_and_return(std::unique_ptr<int> value) {
    return value;
}

// Exam reference implementation. Each thread writes only its own counter,
// and join() makes both results visible here, so no lock is needed.
int combined_total() {
    int first = 0;
    int second = 0;
    std::thread first_worker([&first] {
        for (int i = 0; i < 10000; ++i) ++first;
    });
    std::thread second_worker([&second] {
        for (int i = 0; i < 10000; ++i) ++second;
    });
    first_worker.join();
    second_worker.join();
    return first + second;
}
