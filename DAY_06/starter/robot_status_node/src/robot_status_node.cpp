#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/set_bool.hpp"

using namespace std::chrono_literals;

class RobotStatusNode : public rclcpp::Node {
public:
    RobotStatusNode() : Node("robot_status_node") {
        // TODO: create publisher on /robot/status (std_msgs::msg::String, depth 10).
        // TODO: create subscription on /robot/command.
        // TODO: create SetBool service on /robot/enable_status.
        // TODO: create 500 ms wall timer.
    }

private:
    void publish_status() {
        // TODO: publish command_state_ only when publishing_enabled_ is true.
    }

    // TODO: implement command callback.
    // TODO: implement service callback.

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::string command_state_{"IDLE"};
    bool publishing_enabled_{true};
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotStatusNode>());
    rclcpp::shutdown();
    return 0;
}
