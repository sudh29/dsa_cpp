#include <iostream>
#include <stack>

using namespace std;

class SpecialStack {
private:
    stack<int> s;
    int minEle;

public:
    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        } else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        } else {
            s.push(x);
        }
    }

    int pop() {
        if (s.empty()) return -1;
        int t = s.top();
        s.pop();
        if (t < minEle) {
            int prevMin = minEle;
            minEle = 2 * minEle - t;
            return prevMin;
        }
        return t;
    }

    int getMin() {
        if (s.empty()) return -1;
        return minEle;
    }
};

int main() {
    SpecialStack s;
    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);
    cout << "Current Min: " << s.getMin() << endl; // 15
    s.pop();
    s.pop();
    cout << "Min after popping 16 and 15: " << s.getMin() << endl; // 18
    return 0;
}
