// Day 3 tests: main assignment, both challenges, and the exam coding task.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/solutions.cpp"
#endif
#include SOLUTION_FILE

#include <string>
#include <unordered_map>
#include <vector>

#include "../../common/check.hpp"

namespace {

std::vector<std::string> ids_of(const std::vector<RobotState>& robots) {
    std::vector<std::string> ids;
    for (const auto& robot : robots) ids.push_back(robot.id);
    return ids;
}

}  // namespace

int main() {
    // Main assignment
    FleetManager fleet;
    CHECK(fleet.add_robot({"R-03", "Scout", 80, true}));
    CHECK(fleet.add_robot({"R-01", "Mapper", 35, true}));
    CHECK(fleet.add_robot({"R-02", "Carrier", 18, false}));
    CHECK(!fleet.add_robot({"R-01", "Duplicate", 50, true}));
    CHECK(!fleet.add_robot({"", "NoId", 50, true}));
    CHECK(fleet.update_battery("R-01", 15));
    CHECK(!fleet.update_battery("R-02", 140));
    CHECK(!fleet.update_battery("R-02", -1));
    CHECK(!fleet.update_battery("R-99", 50));
    CHECK(fleet.find_robot("R-99") == nullptr);
    CHECK(fleet.find_robot("R-02") != nullptr && fleet.find_robot("R-02")->battery_percent == 18);
    CHECK((ids_of(fleet.low_battery_robots(20)) == std::vector<std::string>{"R-01", "R-02"}));
    CHECK(fleet.low_battery_robots(15).empty());
    CHECK((fleet.sorted_ids() == std::vector<std::string>{"R-01", "R-02", "R-03"}));

    // Challenge 1
    const auto counts = count_values({2, 1, 2, 3, 1, 2});
    CHECK(counts.size() == 3);
    CHECK(counts.size() == 3 && counts.at(2) == 3 && counts.at(1) == 2 && counts.at(3) == 1);
    CHECK(count_values({}).empty());

    // Challenge 2
    const std::vector<RobotState> robots{
        {"R-03", "Scout", 80, true},
        {"R-01", "Mapper", 80, true},
        {"R-02", "Carrier", 95, false},
        {"R-04", "Spare", 10, true},
    };
    CHECK((ids_of(top_battery_robots(robots, 3)) ==
           std::vector<std::string>{"R-02", "R-01", "R-03"}));
    CHECK(top_battery_robots(robots, 0).empty());
    CHECK(top_battery_robots(robots, 10).size() == 4);
    CHECK(robots.front().id == "R-03");

    // Exam Part A
    const std::vector<int> values{4, 2, 4, 1, 2};
    CHECK((unique_sorted(values) == std::vector<int>{1, 2, 4}));
    CHECK((values == std::vector<int>{4, 2, 4, 1, 2}));
    CHECK(unique_sorted({}).empty());

    return bootcamp::report("Day 3 tests");
}
