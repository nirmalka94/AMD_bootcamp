// Day 8 tests: mock coding round, LRU challenge, and the exam coding task.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/mock_coding_solution.cpp"
#endif
#include SOLUTION_FILE

#include <stdexcept>
#include <vector>

#include "../../common/check.hpp"

int main() {
    // Round 1 mock coding
    const auto latest = latest_event_per_robot({
        {2, 100, "MOVE"}, {1, 120, "STOP"}, {2, 150, "PICK"}, {1, 120, "RESET"}, {3, 90, "IDLE"},
        {3, 80, "OLD"},
    });
    CHECK(latest.size() == 3);
    CHECK(latest.size() == 3 && latest[0].robot_id == 1 && latest[0].type == "RESET");
    CHECK(latest.size() == 3 && latest[1].robot_id == 2 && latest[1].type == "PICK");
    CHECK(latest.size() == 3 && latest[2].robot_id == 3 && latest[2].type == "IDLE");
    CHECK(latest_event_per_robot({}).empty());

    // Challenge 1
    LruCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    CHECK(cache.get(1) == 10);  // 1 is now most recent
    cache.put(3, 30);           // evicts 2
    CHECK(cache.get(2) == -1);
    CHECK(cache.get(3) == 30);
    cache.put(1, 11);           // update moves 1 to front
    cache.put(4, 40);           // evicts 3
    CHECK(cache.get(3) == -1);
    CHECK(cache.get(1) == 11);
    CHECK(cache.get(4) == 40);
    CHECK(cache.get(99) == -1);
    bool rejected_zero = false;
    try {
        LruCache invalid(0);
    } catch (const std::invalid_argument&) {
        rejected_zero = true;
    }
    CHECK(rejected_zero);

    // Exam Part A
    CHECK((most_frequent({1, 1, 2, 2, 3}, 2) == std::vector<int>{1, 2}));
    CHECK((most_frequent({5, 3, 3, 5, 7, 7, 7}, 2) == std::vector<int>{7, 3}));
    CHECK((most_frequent({4, 4, 1}, 10) == std::vector<int>{4, 1}));
    CHECK(most_frequent({}, 3).empty());
    CHECK(most_frequent({1, 2}, 0).empty());

    return bootcamp::report("Day 8 tests");
}
