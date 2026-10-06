#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

struct Interval {
    int low;
    int high;
};

std::vector<std::pair<Interval, Interval>> findConflictingAppointments(std::vector<Interval> appt) {
    std::sort(appt.begin(), appt.end(), [](const Interval &a, const Interval &b) {
        return a.low < b.low;
    });

    std::vector<std::pair<Interval, Interval>> conflicts;
    for (size_t i = 1; i < appt.size(); ++i) {
        if (appt[i].low < appt[i - 1].high) {
            conflicts.push_back({appt[i], appt[i - 1]});
        }
    }
    return conflicts;
}

int main() {
    std::vector<Interval> appt = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    auto conflicts = findConflictingAppointments(appt);

    assert(!conflicts.empty());
    // Verify each detected pair actually conflicts
    for (const auto &[curr, prev] : conflicts) {
        assert(curr.low < prev.high);
    }

    std::vector<Interval> noConflict = {{1, 3}, {3, 5}, {6, 8}};
    auto emptyConflicts = findConflictingAppointments(noConflict);
    assert(emptyConflicts.empty());

    std::cout << "7_bst 17_Given_n_appointments_find_conflicting_appointments: All tests passed.\n";
    return 0;
}
