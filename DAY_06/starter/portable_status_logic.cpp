// Portable fallback for Day 6 when ROS 2 is not installed.
// StatusLogic holds the same state machine as robot_status_node; its methods
// play the role of the node's callbacks. SerialExecutor stands in for the
// rclcpp single-threaded executor: it runs ready callbacks one at a time.
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#include "../../common/check.hpp"

class StatusLogic {
public:
    // Subscription callback for /robot/command.
    // "START" -> "RUNNING", "STOP" -> "STOP", anything else -> "UNKNOWN".
    void on_command(const std::string& command) {
        // TODO
    }

    // Service callback for /robot/enable_status (SetBool).
    // Store the flag and return "Publishing enabled" or "Publishing disabled".
    std::string on_enable_status(bool enable) {
        // TODO
        return {};
    }

    // Timer callback. When publishing is enabled, set `message` to the current
    // command state and return true; otherwise return false and publish nothing.
    bool on_timer(std::string& message) const {
        // TODO
        return false;
    }

private:
    std::string command_state_{"IDLE"};
    bool publishing_enabled_{true};
};

// Supplied: do not change. Callbacks posted here run serially, in order.
class SerialExecutor {
public:
    void post(std::function<void()> callback) { ready_.push(std::move(callback)); }

    void spin_until_empty() {
        while (!ready_.empty()) {
            auto callback = std::move(ready_.front());
            ready_.pop();
            callback();
        }
    }

private:
    std::queue<std::function<void()>> ready_;
};

int main() {
    StatusLogic logic;
    SerialExecutor executor;
    std::vector<std::string> published;

    const auto timer_tick = [&logic, &published] {
        std::string message;
        if (logic.on_timer(message)) published.push_back(message);
    };

    executor.post(timer_tick);
    executor.post([&logic] { logic.on_command("START"); });
    executor.post(timer_tick);
    executor.post([&logic] { logic.on_enable_status(false); });
    executor.post(timer_tick);  // publishing disabled: nothing is published
    executor.post([&logic] { logic.on_command("STOP"); });
    executor.post([&logic] { logic.on_enable_status(true); });
    executor.post(timer_tick);
    executor.post([&logic] { logic.on_command("JUMP"); });
    executor.post(timer_tick);
    executor.spin_until_empty();

    for (const auto& message : published) std::cout << "/robot/status: " << message << '\n';

    // Self-checks: each failing line is reported until StatusLogic is correct.
    CHECK((published == std::vector<std::string>{"IDLE", "RUNNING", "STOP", "UNKNOWN"}));
    CHECK(logic.on_enable_status(false) == "Publishing disabled");
    CHECK(logic.on_enable_status(true) == "Publishing enabled");
    return bootcamp::report("Day 6 portable status logic");
}
