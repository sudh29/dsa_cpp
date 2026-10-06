#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int low, high;
};

void printConflictingAppointments(vector<Interval> appt) {
    sort(appt.begin(), appt.end(), [](const Interval &a, const Interval &b) {
        return a.low < b.low;
    });

    cout << "Conflicting appointments:\n";
    for (size_t i = 1; i < appt.size(); i++) {
        if (appt[i].low < appt[i - 1].high) {
            cout << "[" << appt[i].low << "," << appt[i].high << "] conflicts with ["
                 << appt[i - 1].low << "," << appt[i - 1].high << "]\n";
        }
    }
}

int main() {
    vector<Interval> appt = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    printConflictingAppointments(appt);
    return 0;
}
