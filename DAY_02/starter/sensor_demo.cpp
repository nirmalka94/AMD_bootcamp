#include <iostream>
#include <memory>
#include <string>

#include "../../common/check.hpp"

class DistanceSensor {
public:
    explicit DistanceSensor(std::string name);

    bool update_reading(double value);
    double reading() const;
    std::string name() const;
    std::string status() const;

private:
    std::string name_;
    double last_reading_m_{0.0};
};

DistanceSensor::DistanceSensor(std::string name)
    : name_(/* TODO */), last_reading_m_(/* TODO */) {
}

bool DistanceSensor::update_reading(double value) {
    // TODO: accept [0.0, 20.0], preserve old value if invalid.
    return false;
}

double DistanceSensor::reading() const {
    // TODO
    return 0.0;
}

std::string DistanceSensor::name() const {
    // TODO
    return {};
}

std::string DistanceSensor::status() const {
    // TODO: STOP < 0.20, SLOW < 0.50, otherwise NORMAL.
    return "UNKNOWN";
}

int main() {
    DistanceSensor front_sensor{"front_range"};
    front_sensor.update_reading(0.35);
    const bool accepted = front_sensor.update_reading(25.0);

    std::cout << front_sensor.name() << '\n';
    std::cout << "Invalid update accepted? " << std::boolalpha << accepted << '\n';
    std::cout << "Current reading: " << front_sensor.reading() << " m\n";
    std::cout << "Status: " << front_sensor.status() << '\n';

    auto rear_sensor = std::make_unique<DistanceSensor>("rear_range");
    rear_sensor->update_reading(1.2);
    std::cout << rear_sensor->name() << ": " << rear_sensor->status() << '\n';

    // Self-checks: each failing line is reported until the class is correct.
    CHECK(front_sensor.name() == "front_range");
    CHECK(!accepted);
    CHECK(front_sensor.reading() == 0.35);
    CHECK(front_sensor.status() == "SLOW");
    CHECK(rear_sensor->status() == "NORMAL");

    DistanceSensor boundary{"boundary"};
    CHECK(boundary.reading() == 0.0);
    CHECK(boundary.update_reading(0.0) && boundary.status() == "STOP");
    CHECK(boundary.update_reading(0.20) && boundary.status() == "SLOW");
    CHECK(boundary.update_reading(0.50) && boundary.status() == "NORMAL");
    CHECK(boundary.update_reading(20.0));
    CHECK(!boundary.update_reading(-0.1));
    CHECK(boundary.reading() == 20.0);
    return bootcamp::report("Day 2 sensor model");
}
