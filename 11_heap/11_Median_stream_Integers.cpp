#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxH; // lower half
    priority_queue<int, vector<int>, greater<int>> minH; // upper half

public:
    void insert(int x) {
        if (maxH.empty() || x <= maxH.top()) {
            maxH.push(x);
        } else {
            minH.push(x);
        }

        // Balance heaps
        if (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        } else if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    double getMedian() {
        if (maxH.size() == minH.size()) {
            return (maxH.top() + minH.top()) / 2.0;
        }
        return maxH.top();
    }
};

int main() {
    MedianFinder mf;
    vector<int> stream = {5, 15, 1, 3};
    for (int x : stream) {
        mf.insert(x);
        cout << "Added " << x << " -> Median: " << mf.getMedian() << endl;
    }
    return 0;
}
