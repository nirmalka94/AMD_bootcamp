// Day 2 tests: main assignment, both challenges, and the exam coding task.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/solutions.cpp"
#endif
#include SOLUTION_FILE

#include <memory>
#include <string>
#include <utility>

#include "../../common/check.hpp"

int main() {
    // Main assignment
    DistanceSensor sensor{"front"};
    CHECK(sensor.name() == "front");
    CHECK(sensor.reading() == 0.0);
    CHECK(sensor.status() == "STOP");
    CHECK(sensor.update_reading(0.35));
    CHECK(sensor.status() == "SLOW");
    CHECK(!sensor.update_reading(25.0));
    CHECK(!sensor.update_reading(-0.1));
    CHECK(sensor.reading() == 0.35);
    CHECK(sensor.update_reading(20.0) && sensor.status() == "NORMAL");
    CHECK(sensor.update_reading(0.50) && sensor.status() == "NORMAL");
    CHECK(sensor.update_reading(0.20) && sensor.status() == "SLOW");

    // Challenge 1
    CHECK(Battery{120}.percentage() == 100);
    CHECK(Battery{-5}.percentage() == 0);
    Battery battery{50};
    CHECK(!battery.set_percentage(-1));
    CHECK(!battery.set_percentage(101));
    CHECK(battery.percentage() == 50);
    CHECK(battery.set_percentage(15) && battery.is_low());
    CHECK(battery.set_percentage(20) && !battery.is_low());

    // Challenge 2
    auto made = make_sensor("rear");
    CHECK(made != nullptr && made->name() == "rear");
    auto new_owner = std::move(made);
    CHECK(made == nullptr);
    CHECK(new_owner != nullptr);

    // Exam Part A
    Motor motor{"left_wheel"};
    CHECK(motor.name() == "left_wheel");
    CHECK(motor.speed() == 0.0);
    CHECK(motor.set_speed(-1.0));
    CHECK(!motor.set_speed(1.5));
    CHECK(motor.speed() == -1.0);
    CHECK(motor.set_speed(1.0) && motor.speed() == 1.0);

    return bootcamp::report("Day 2 tests");
}
