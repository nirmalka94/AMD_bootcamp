// Day 08 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=08 SRC=DAY_08/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
#include <algorithm>
#include <cstddef>
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// ===== Round 1 mock coding: latest event per robot =====
// TODO: copy your finished function from starter/mock_coding.cpp.
struct Event {
    int robot_id;
    int timestamp_ms;
    std::string type;
};

std::vector<Event> latest_event_per_robot(const std::vector<Event>& events) {
    // TODO: latest event per robot_id (later input wins ties), sorted by robot_id.
    return {};
}

// ===== Challenge 1: LRU cache =====
class LruCache {
public:
    explicit LruCache(std::size_t capacity) {
        // TODO: store capacity; throw std::invalid_argument if it is 0.
    }

    int get(int key) {
        // TODO: value for key (and mark it most recent), or -1.
        return -1;
    }

    void put(int key, int value) {
        // TODO: insert or update; evict the least recently used key when full.
    }

private:
    // TODO: add the members you need.
};

// ===== Challenge 2: concurrency design =====
// A written answer; not tested by `make test`.

// ===== Exam Part A: most frequent values =====
std::vector<int> most_frequent(const std::vector<int>& values, std::size_t k) {
    // TODO: up to k distinct values by frequency (descending), ties by value (ascending).
    return {};
}
