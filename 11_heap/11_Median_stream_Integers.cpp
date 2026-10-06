#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> maxH; // lower half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minH; // upper half

public:
    void insert(int x) {
        if (maxH.empty() || x <= maxH.top()) {
            maxH.push(x);
        } else {
            minH.push(x);
        }

        // Balance heaps: maxH can have at most 1 more element than minH
        if (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        } else if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    double getMedian() const {
        if (maxH.empty() && minH.empty()) return 0.0;
        if (maxH.size() == minH.size()) {
            return (maxH.top() + minH.top()) / 2.0;
        }
        return static_cast<double>(maxH.top());
    }
};

int main() {
    MedianFinder mf;
    std::vector<int> stream = {5, 15, 1, 3};
    // Stream additions:
    // 5 -> median: 5.0
    // 15 -> median: (5 + 15) / 2 = 10.0
    // 1 -> median: 5.0
    // 3 -> median: (3 + 5) / 2 = 4.0
    std::vector<double> expected = {5.0, 10.0, 5.0, 4.0};

    for (size_t i = 0; i < stream.size(); ++i) {
        mf.insert(stream[i]);
        assert(std::abs(mf.getMedian() - expected[i]) < 1e-6);
    }

    std::cout << "11_heap 11_Median_stream_Integers: All tests passed.\n";
    return 0;
}
