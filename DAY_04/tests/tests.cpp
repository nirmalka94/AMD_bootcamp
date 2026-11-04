// Day 4 tests: main assignment, both challenges, and the exam coding task.
// Builds against the instructor solutions unless SOLUTION_FILE names another file.
#ifndef SOLUTION_FILE
#define SOLUTION_FILE "../instructor_solutions/solutions.cpp"
#endif
#include SOLUTION_FILE

#include <algorithm>
#include <string>
#include <vector>

#include "../../common/check.hpp"

int main() {
    // Main assignment
    CHECK(has_pair_with_sum({2, 7, 11, 15}, 9));
    CHECK(!has_pair_with_sum({2, 7, 11, 15}, 100));
    CHECK(!has_pair_with_sum({5}, 10));
    CHECK(has_pair_with_sum({5, 5}, 10));
    CHECK(has_pair_with_sum({-3, 4, 1}, 1));
    CHECK(!has_pair_with_sum({}, 0));
    const std::vector<int> samples{2, 1, 5, 1, 3, 2};
    CHECK(max_window_sum(samples, 3) == 9);
    CHECK(max_window_sum(samples, 1) == 5);
    CHECK(max_window_sum(samples, 6) == 14);
    CHECK(max_window_sum(samples, 0) == 0);
    CHECK(max_window_sum(samples, 7) == 0);
    CHECK(max_window_sum({-4, -2, -7}, 2) == -6);
    CHECK(valid_delimiters("cmd({x[0]})"));
    CHECK(valid_delimiters(""));
    CHECK(!valid_delimiters("(]"));
    CHECK(!valid_delimiters("(("));
    CHECK(!valid_delimiters(")("));

    // Challenge 1
    CHECK(first_unique_index("swiss") == 1);
    CHECK(first_unique_index("aabb") == -1);
    CHECK(first_unique_index("") == -1);
    CHECK(first_unique_index("abca") == 1);

    // Challenge 2 (also compared with std::lower_bound)
    CHECK(lower_bound_index({1, 2, 2, 4}, 2) == 1);
    CHECK(lower_bound_index({1, 3, 5}, 4) == 2);
    CHECK(lower_bound_index({1, 3, 5}, 9) == 3);
    CHECK(lower_bound_index({1, 3, 5}, 0) == 0);
    CHECK(lower_bound_index({}, 7) == 0);
    const std::vector<int> sorted{1, 1, 2, 3, 5, 8, 13};
    for (int target = 0; target <= 14; ++target) {
        const auto expected = static_cast<std::size_t>(
            std::lower_bound(sorted.begin(), sorted.end(), target) - sorted.begin());
        CHECK(lower_bound_index(sorted, target) == expected);
    }

    // Exam Part A
    CHECK(longest_unique_substring_length("abcabcbb") == 3);
    CHECK(longest_unique_substring_length("bbbbb") == 1);
    CHECK(longest_unique_substring_length("") == 0);
    CHECK(longest_unique_substring_length("pwwkew") == 3);
    CHECK(longest_unique_substring_length("abba") == 2);

    return bootcamp::report("Day 4 tests");
}
