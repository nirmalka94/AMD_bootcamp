// Day 5 tests: main assignment, both challenges, and the exam coding task.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
// Run under ThreadSanitizer too (`make check` does both).
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/solutions.cpp"
#endif
#include SOLUTION_FILE

#include <memory>
#include <thread>
#include <utility>
#include <vector>

#include "../../common/check.hpp"

int main() {
    // Main assignment: every sample consumed exactly once, in order, through a small buffer.
    SensorQueue queue(4);
    std::vector<int> consumed;
    std::thread producer([&queue] {
        for (int sample = 1; sample <= 1000; ++sample) {
            if (!queue.push(sample)) break;
        }
        queue.close();
    });
    std::thread consumer([&queue, &consumed] {
        int sample = 0;
        while (queue.pop(sample)) consumed.push_back(sample);
    });
    producer.join();
    consumer.join();
    bool in_order = consumed.size() == 1000;
    for (std::size_t i = 0; in_order && i < consumed.size(); ++i) {
        in_order = consumed[i] == static_cast<int>(i) + 1;
    }
    CHECK(in_order);

    // close() drains remaining items, then rejects further work.
    SensorQueue drained(2);
    CHECK(drained.push(7));
    drained.close();
    int value = 0;
    CHECK(drained.pop(value) && value == 7);
    CHECK(!drained.pop(value));
    CHECK(!drained.push(8));

    // close() wakes a consumer that is already blocked on an empty queue.
    SensorQueue idle(1);
    bool popped = true;
    std::thread waiter([&idle, &popped] {
        int unused = 0;
        popped = idle.pop(unused);
    });
    idle.close();
    waiter.join();
    CHECK(!popped);

    // Challenge 1
    ThreadSafeCounter counter;
    std::vector<std::thread> workers;
    for (int t = 0; t < 4; ++t) {
        workers.emplace_back([&counter] {
            for (int i = 0; i < 25000; ++i) counter.increment();
        });
    }
    for (auto& worker : workers) worker.join();
    CHECK(counter.value() == 100000);

    // Challenge 2
    auto original = std::make_unique<int>(42);
    auto returned = take_and_return(std::move(original));
    CHECK(original == nullptr);
    CHECK(returned != nullptr && *returned == 42);

    // Exam Part A
    CHECK(combined_total() == 20000);

    return bootcamp::report("Day 5 tests");
}
