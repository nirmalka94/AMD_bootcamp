// Day 02 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=02 SRC=DAY_02/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
#include <algorithm>
#include <memory>
#include <string>
#include <utility>

// ===== Main assignment: distance sensor model =====
// TODO: copy your finished class from starter/sensor_demo.cpp.
class DistanceSensor {
public:
    explicit DistanceSensor(std::string name) : name_(std::move(name)) {}

    bool update_reading(double value) {
        // TODO: accept [0.0, 20.0]; keep the old value and return false otherwise.
        return false;
    }

    double reading() const { return last_reading_m_; }
    std::string name() const { return name_; }

    std::string status() const {
        // TODO: STOP < 0.20, SLOW < 0.50, otherwise NORMAL.
        return "UNKNOWN";
    }

private:
    std::string name_;
    double last_reading_m_{0.0};
};

// ===== Challenge 1: battery class =====
class Battery {
public:
    explicit Battery(int percentage) {
        // TODO: clamp the initial value to [0, 100] (prefer a member initialiser list).
    }

    bool set_percentage(int value) {
        // TODO: reject values outside [0, 100] without changing the stored value.
        return false;
    }

    int percentage() const { return percentage_; }

    bool is_low() const {
        // TODO: true below 20%.
        return false;
    }

private:
    int percentage_{0};
};

// ===== Challenge 2: exclusive sensor ownership =====
std::unique_ptr<DistanceSensor> make_sensor(const std::string& name) {
    // TODO: create the sensor with std::make_unique.
    return nullptr;
}

// ===== Exam Part A: motor class =====
class Motor {
public:
    explicit Motor(std::string name) {
        // TODO: store the name; speed starts at zero.
    }

    bool set_speed(double value) {
        // TODO: accept [-1.0, 1.0]; keep the old speed otherwise.
        return false;
    }

    double speed() const { return speed_; }

    std::string name() const {
        // TODO
        return {};
    }

private:
    std::string name_;
    double speed_{0.0};
};
