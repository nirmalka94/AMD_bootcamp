#include <algorithm>
#include <cstddef>
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct Event {
    int robot_id;
    int timestamp_ms;
    std::string type;
};

std::vector<Event> latest_event_per_robot(const std::vector<Event>& events) {
    std::unordered_map<int, Event> latest;
    for (const auto& event : events) {
        auto it = latest.find(event.robot_id);
        if (it == latest.end() || event.timestamp_ms >= it->second.timestamp_ms) {
            latest[event.robot_id] = event;
        }
    }

    std::vector<Event> result;
    result.reserve(latest.size());
    for (const auto& entry : latest) result.push_back(entry.second);
    std::sort(result.begin(), result.end(),
              [](const Event& a, const Event& b) {
                  return a.robot_id < b.robot_id;
              });
    return result;
}

// Challenge 1 reference implementation. The list keeps keys in recency order
// (front = most recent); the map stores list iterators so a hit can be moved
// to the front with splice in O(1), without searching the list.
class LruCache {
public:
    explicit LruCache(std::size_t capacity) : capacity_(capacity) {
        if (capacity_ == 0) throw std::invalid_argument("LRU capacity must be positive");
    }

    int get(int key) {
        const auto it = index_.find(key);
        if (it == index_.end()) return -1;
        order_.splice(order_.begin(), order_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = index_.find(key);
        if (it != index_.end()) {
            it->second->second = value;
            order_.splice(order_.begin(), order_, it->second);
            return;
        }
        if (order_.size() == capacity_) {
            index_.erase(order_.back().first);
            order_.pop_back();
        }
        order_.emplace_front(key, value);
        index_[key] = order_.begin();
    }

private:
    using Entry = std::pair<int, int>;  // key, value

    std::size_t capacity_;
    std::list<Entry> order_;
    std::unordered_map<int, std::list<Entry>::iterator> index_;
};

// Exam reference implementation: count, then sort distinct values by
// (frequency descending, value ascending). O(n + m log m) time, O(m) space,
// where m is the number of distinct values.
std::vector<int> most_frequent(const std::vector<int>& values, std::size_t k) {
    std::unordered_map<int, int> counts;
    for (int value : values) ++counts[value];

    std::vector<std::pair<int, int>> entries(counts.begin(), counts.end());
    std::sort(entries.begin(), entries.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  if (a.second != b.second) return a.second > b.second;
                  return a.first < b.first;
              });

    std::vector<int> result;
    for (std::size_t i = 0; i < entries.size() && i < k; ++i) {
        result.push_back(entries[i].first);
    }
    return result;
}
