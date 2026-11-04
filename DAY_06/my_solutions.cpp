// Day 06 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=06 SRC=DAY_06/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
//
// Day 6 note: only the main assignment's logic is tested here, through the
// portable StatusLogic. The challenges and the exam task are ROS 2 code; build
// and run those in your ROS package as described in CHALLENGES.md and EXAM.md.
#include <string>

// ===== Main assignment: status logic (same callbacks as robot_status_node) =====
// TODO: copy your finished class from starter/portable_status_logic.cpp,
// or move the callback logic out of your ROS node into this class.
class StatusLogic {
public:
    void on_command(const std::string& command) {
        // TODO: "START" -> "RUNNING", "STOP" -> "STOP", anything else -> "UNKNOWN".
    }

    std::string on_enable_status(bool enable) {
        // TODO: store the flag; return "Publishing enabled" or "Publishing disabled".
        return {};
    }

    bool on_timer(std::string& message) const {
        // TODO: when enabled, set message to the command state and return true.
        return false;
    }

private:
    std::string command_state_{"IDLE"};
    bool publishing_enabled_{true};
};

// ===== Challenge 1: battery warning =====
// Done in your ROS node (robot_status_node.cpp). Not tested by `make test`.

// ===== Challenge 2: command counter =====
// Done in your ROS node (robot_status_node.cpp). Not tested by `make test`.

// ===== Exam Part A: /cmd_vel listener =====
// A ROS 2 code fragment; write it on paper or in your package. Not tested by `make test`.
