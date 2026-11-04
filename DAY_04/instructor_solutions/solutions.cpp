#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool has_pair_with_sum(const std::vector<int>& values, int target) {
    std::unordered_set<int> seen;
    for (int value : values) {
        if (seen.count(target - value)) return true;
        seen.insert(value);
    }
    return false;
}

int max_window_sum(const std::vector<int>& values, std::size_t k) {
    if (k == 0 || k > values.size()) return 0;
    int sum = 0;
    for (std::size_t i = 0; i < k; ++i) sum += values[i];
    int best = sum;
    for (std::size_t right = k; right < values.size(); ++right) {
        sum += values[right] - values[right - k];
        if (sum > best) best = sum;
    }
    return best;
}

bool valid_delimiters(const std::string& text) {
    std::stack<char> openings;
    for (char c : text) {
        if (c == '(' || c == '[' || c == '{') {
            openings.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (openings.empty()) return false;
            const char open = openings.top();
            openings.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) return false;
        }
    }
    return openings.empty();
}

// Challenge 1 reference implementation: count first, then scan in original order.
int first_unique_index(const std::string& text) {
    std::unordered_map<char, int> counts;
    for (char c : text) ++counts[c];
    for (std::size_t i = 0; i < text.size(); ++i) {
        if (counts[text[i]] == 1) return static_cast<int>(i);
    }
    return -1;
}

// Challenge 2 reference implementation. The answer always lies in [low, high).
std::size_t lower_bound_index(const std::vector<int>& sorted, int target) {
    std::size_t low = 0;
    std::size_t high = sorted.size();
    while (low < high) {
        const std::size_t mid = low + (high - low) / 2;
        if (sorted[mid] < target) low = mid + 1;
        else high = mid;
    }
    return low;
}

// Exam reference implementation: variable-size window [start, i] with no repeats.
int longest_unique_substring_length(const std::string& text) {
    std::unordered_map<char, std::size_t> last_seen;
    std::size_t start = 0;
    std::size_t best = 0;
    for (std::size_t i = 0; i < text.size(); ++i) {
        const auto it = last_seen.find(text[i]);
        if (it != last_seen.end() && it->second >= start) start = it->second + 1;
        last_seen[text[i]] = i;
        best = std::max(best, i - start + 1);
    }
    return static_cast<int>(best);
}
