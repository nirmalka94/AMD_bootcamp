// Day 6 tests: the portable StatusLogic. The ROS 2 packages are checked with `make ros`.
// Builds against the instructor solution unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/portable_status_logic.cpp"
#endif
#include SOLUTION_FILE

#include <string>

#include "../../common/check.hpp"

int main() {
    StatusLogic logic;
    std::string message;

    CHECK(logic.on_timer(message) && message == "IDLE");
    logic.on_command("START");
    CHECK(logic.on_timer(message) && message == "RUNNING");
    logic.on_command("STOP");
    CHECK(logic.on_timer(message) && message == "STOP");
    logic.on_command("start");  // commands are case-sensitive
    CHECK(logic.on_timer(message) && message == "UNKNOWN");

    CHECK(logic.on_enable_status(false) == "Publishing disabled");
    message = "unchanged";
    CHECK(!logic.on_timer(message));
    CHECK(message == "unchanged");
    logic.on_command("START");  // state still updates while publishing is off
    CHECK(logic.on_enable_status(true) == "Publishing enabled");
    CHECK(logic.on_timer(message) && message == "RUNNING");

    return bootcamp::report("Day 6 tests");
}
