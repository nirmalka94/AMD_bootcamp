#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../common/check.hpp"

struct Event {
    int robot_id;
    int timestamp_ms;
    std::string type;
};

// Implement a function that returns the latest event per robot_id.
// If timestamps tie, the later event in the input wins.
// Output should be sorted by robot_id.
std::vector<Event> latest_event_per_robot(const std::vector<Event>& events) {
    // TODO
    return {};
}

int main() {
    const std::vector<Event> events{
        {2, 100, "MOVE"},
        {1, 120, "STOP"},
        {2, 150, "PICK"},
        {1, 120, "RESET"}
    };

    const auto result = latest_event_per_robot(events);
    for (const auto& event : result) {
        std::cout << event.robot_id << " " << event.timestamp_ms
                  << " " << event.type << '\n';
    }

    // Self-checks: run these only after you have tested your own cases.
    CHECK(result.size() == 2);
    CHECK(result.size() == 2 && result[0].robot_id == 1 && result[0].type == "RESET");
    CHECK(result.size() == 2 && result[1].robot_id == 2 && result[1].type == "PICK");
    CHECK(latest_event_per_robot({}).empty());
    return bootcamp::report("Day 8 mock coding");
}
