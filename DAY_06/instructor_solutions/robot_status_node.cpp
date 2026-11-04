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
        publisher_ = create_publisher<std_msgs::msg::String>("/robot/status", 10);
        subscription_ = create_subscription<std_msgs::msg::String>(
            "/robot/command", 10,
            [this](std_msgs::msg::String::ConstSharedPtr msg) {
                if (msg->data == "START") command_state_ = "RUNNING";
                else if (msg->data == "STOP") command_state_ = "STOP";
                else command_state_ = "UNKNOWN";
            });
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
    void publish_status() {
        if (!publishing_enabled_) return;
        std_msgs::msg::String message;
        message.data = command_state_;
        publisher_->publish(message);
    }

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
