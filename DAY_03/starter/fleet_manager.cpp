#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../../common/check.hpp"

struct RobotState {
    std::string id;
    std::string name;
    int battery_percent{100};
    bool online{true};
};

class FleetManager {
public:
    bool add_robot(const RobotState& robot) {
        // TODO: reject empty and duplicate IDs.
        return false;
    }

    bool update_battery(const std::string& id, int battery_percent) {
        // TODO: reject unknown ID and values outside [0, 100].
        return false;
    }

    const RobotState* find_robot(const std::string& id) const {
        // TODO: return pointer to record or nullptr.
        return nullptr;
    }

    std::vector<RobotState> low_battery_robots(int threshold) const {
        // TODO: return records strictly below threshold.
        return {};
    }

    std::vector<std::string> sorted_ids() const {
        // TODO: return all IDs in ascending order.
        return {};
    }

private:
    std::vector<RobotState> robots_;
};

int main() {
    FleetManager fleet;
    CHECK(fleet.add_robot({"R-03", "Scout", 80, true}));
    CHECK(fleet.add_robot({"R-01", "Mapper", 35, true}));
    CHECK(fleet.add_robot({"R-02", "Carrier", 18, false}));

    CHECK(fleet.update_battery("R-01", 15));
    const bool invalid_update = fleet.update_battery("R-02", 140);

    std::cout << "Invalid update accepted: " << std::boolalpha
              << invalid_update << '\n';
    std::cout << "Low battery robots:\n";
    std::vector<std::string> low_ids;
    for (const auto& robot : fleet.low_battery_robots(20)) {
        std::cout << robot.id << " " << robot.battery_percent << "%\n";
        low_ids.push_back(robot.id);
    }
    std::cout << "Sorted IDs:";
    for (const auto& id : fleet.sorted_ids()) std::cout << " " << id;
    std::cout << '\n';

    // Self-checks: each failing line is reported until the manager is correct.
    CHECK(!invalid_update);
    CHECK(!fleet.add_robot({"R-01", "Duplicate", 50, true}));
    CHECK(!fleet.add_robot({"", "NoId", 50, true}));
    CHECK(!fleet.update_battery("R-99", 50));
    CHECK(fleet.find_robot("R-99") == nullptr);
    const RobotState* mapper = fleet.find_robot("R-01");
    CHECK(mapper != nullptr && mapper->battery_percent == 15);
    CHECK((low_ids == std::vector<std::string>{"R-01", "R-02"}));
    CHECK((fleet.sorted_ids() == std::vector<std::string>{"R-01", "R-02", "R-03"}));
    return bootcamp::report("Day 3 fleet manager");
}
