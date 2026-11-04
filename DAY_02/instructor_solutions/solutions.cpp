#include <algorithm>
#include <memory>
#include <string>
#include <utility>

// Complete reference implementation for the learner's main assignment.
class DistanceSensor {
public:
    explicit DistanceSensor(std::string name)
        : name_(std::move(name)), last_reading_m_(0.0) {}

    bool update_reading(double value) {
        if (value < 0.0 || value > 20.0) return false;
        last_reading_m_ = value;
        return true;
    }

    double reading() const { return last_reading_m_; }
    std::string name() const { return name_; }

    std::string status() const {
        if (last_reading_m_ < 0.20) return "STOP";
        if (last_reading_m_ < 0.50) return "SLOW";
        return "NORMAL";
    }

private:
    std::string name_;
    double last_reading_m_;
};

// Challenge 1 reference implementation.
class Battery {
public:
    explicit Battery(int percentage)
        : percentage_(std::clamp(percentage, 0, 100)) {}

    bool set_percentage(int value) {
        if (value < 0 || value > 100) return false;
        percentage_ = value;
        return true;
    }

    int percentage() const { return percentage_; }
    bool is_low() const { return percentage_ < 20; }

private:
    int percentage_;
};

// Challenge 2 reference implementation.
std::unique_ptr<DistanceSensor> make_sensor(const std::string& name) {
    return std::make_unique<DistanceSensor>(name);
}

// Exam reference implementation.
class Motor {
public:
    explicit Motor(std::string name)
        : name_(std::move(name)), speed_(0.0) {}

    bool set_speed(double value) {
        if (value < -1.0 || value > 1.0) return false;
        speed_ = value;
        return true;
    }

    double speed() const { return speed_; }
    std::string name() const { return name_; }

private:
    std::string name_;
    double speed_;
};
