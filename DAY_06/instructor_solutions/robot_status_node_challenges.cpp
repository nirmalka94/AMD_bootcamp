// Reference for both Day 6 challenges: robot_status_node plus a battery
// subscription and START/STOP counters. All callbacks run on the default
// single-threaded executor, so they never overlap and the members need no mutex.
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/set_bool.hpp"

using namespace std::chrono_literals;

class RobotStatusNode : public rclcpp::Node {
public:
    RobotStatusNode() : Node("robot_status_node") {
        publisher_ = create_publisher<std_msgs::msg::String>("/robot/status", 10);
        command_subscription_ = create_subscription<std_msgs::msg::String>(
            "/robot/command", 10,
            [this](std_msgs::msg::String::ConstSharedPtr msg) { on_command(msg->data); });
        battery_subscription_ = create_subscription<std_msgs::msg::Int32>(
            "/robot/battery", 10,
            [this](std_msgs::msg::Int32::ConstSharedPtr msg) { on_battery(msg->data); });
        service_ = create_service<std_srvs::srv::SetBool>(
            "/robot/enable_status",
            [this](const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
                   std::shared_ptr<std_srvs::srv::SetBool::Response> response) {
                publishing_enabled_ = request->data;
                response->success = true;
                response->message = publishing_enabled_ ? "Publishing enabled"
                                                         : "Publishing disabled";
            });
        timer_ = create_wall_timer(500ms, [this] { publish_status(); });
    }

private:
    // Challenge 2: only recognised commands are counted.
    void on_command(const std::string& command) {
        if (command == "START") {
            command_state_ = "RUNNING";
            ++start_count_;
        } else if (command == "STOP") {
            command_state_ = "STOP";
            ++stop_count_;
        } else {
            command_state_ = "UNKNOWN";
        }
    }

    // Challenge 1: the battery callback writes; publish_status (timer) reads.
    void on_battery(std::int32_t percent) {
        if (percent < 0 || percent > 100) {
            RCLCPP_WARN(get_logger(), "Ignoring invalid battery value %d", percent);
            return;
        }
        battery_percent_ = percent;
    }

    std::string status_text() const {
        std::string text = command_state_ + " | battery ";
        if (battery_percent_ < 0) {
            text += "unknown";
        } else {
            text += std::to_string(battery_percent_) + "%";
            if (battery_percent_ < 20) text += " LOW";
        }
        text += " | start " + std::to_string(start_count_) +
                " stop " + std::to_string(stop_count_);
        return text;
    }

    void publish_status() {
        if (!publishing_enabled_) return;
        std_msgs::msg::String message;
        message.data = status_text();
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr command_subscription_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr battery_subscription_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::string command_state_{"IDLE"};
    bool publishing_enabled_{true};
    std::int32_t battery_percent_{-1};  // -1 until the first valid reading arrives
    int start_count_{0};
    int stop_count_{0};
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotStatusNode>());
    rclcpp::shutdown();
    return 0;
}
