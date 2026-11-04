#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

struct RobotState {
    std::string id, name;
    int battery_percent{100};
    bool online{true};
};

class FleetManager {
public:
    bool add_robot(const RobotState& robot) {
        if (robot.id.empty() || find_robot(robot.id)) return false;
        robots_.push_back(robot);
        return true;
    }
    bool update_battery(const std::string& id, int value) {
        if (value < 0 || value > 100) return false;
        for (auto& robot : robots_) {
            if (robot.id == id) {
                robot.battery_percent = value;
                return true;
            }
        }
        return false;
    }
    const RobotState* find_robot(const std::string& id) const {
        for (const auto& robot : robots_)
            if (robot.id == id) return &robot;
        return nullptr;
    }
    std::vector<RobotState> low_battery_robots(int threshold) const {
        std::vector<RobotState> result;
        std::copy_if(robots_.begin(), robots_.end(), std::back_inserter(result),
                     [threshold](const RobotState& r) {
                         return r.battery_percent < threshold;
                     });
        return result;
    }
    std::vector<std::string> sorted_ids() const {
        std::vector<std::string> ids;
        for (const auto& robot : robots_) ids.push_back(robot.id);
        std::sort(ids.begin(), ids.end());
        return ids;
    }
private:
    std::vector<RobotState> robots_;
};

std::unordered_map<int, int> count_values(const std::vector<int>& values) {
    std::unordered_map<int, int> counts;
    for (int value : values) ++counts[value];
    return counts;
}

// Challenge 2 reference implementation. Copying the input keeps the caller's vector unchanged.
std::vector<RobotState> top_battery_robots(const std::vector<RobotState>& robots,
                                           std::size_t count) {
    std::vector<RobotState> ranked = robots;
    std::sort(ranked.begin(), ranked.end(), [](const RobotState& a, const RobotState& b) {
        if (a.battery_percent != b.battery_percent) return a.battery_percent > b.battery_percent;
        return a.id < b.id;
    });
    if (count < ranked.size()) ranked.resize(count);
    return ranked;
}

// Exam reference implementation: sort a copy, then drop adjacent duplicates.
std::vector<int> unique_sorted(const std::vector<int>& values) {
    std::vector<int> result = values;
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}
