// Reference implementation of StatusLogic from starter/portable_status_logic.cpp.
// The callback bodies match robot_status_node.cpp, without rclcpp.
#include <string>

class StatusLogic {
public:
    void on_command(const std::string& command) {
        if (command == "START") command_state_ = "RUNNING";
        else if (command == "STOP") command_state_ = "STOP";
        else command_state_ = "UNKNOWN";
    }

    std::string on_enable_status(bool enable) {
        publishing_enabled_ = enable;
        return publishing_enabled_ ? "Publishing enabled" : "Publishing disabled";
    }

    bool on_timer(std::string& message) const {
        if (!publishing_enabled_) return false;
        message = command_state_;
        return true;
    }

private:
    std::string command_state_{"IDLE"};
    bool publishing_enabled_{true};
};
