// Day 6 exam Part A reference: store the latest linear-x and angular-z from /cmd_vel.
#include <memory>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

class CmdVelListener : public rclcpp::Node {
public:
    CmdVelListener() : Node("cmd_vel_listener") {
        subscription_ = create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10,
            [this](geometry_msgs::msg::Twist::ConstSharedPtr msg) { on_cmd_vel(*msg); });
    }

    double linear_x() const { return linear_x_; }
    double angular_z() const { return angular_z_; }

private:
    void on_cmd_vel(const geometry_msgs::msg::Twist& msg) {
        linear_x_ = msg.linear.x;
        angular_z_ = msg.angular.z;
        RCLCPP_DEBUG(get_logger(), "cmd_vel: linear.x=%.2f angular.z=%.2f", linear_x_, angular_z_);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    double linear_x_{0.0};
    double angular_z_{0.0};
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CmdVelListener>());
    rclcpp::shutdown();
    return 0;
}
