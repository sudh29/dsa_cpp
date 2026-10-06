#include <cassert>
#include <iostream>
#include <vector>

class KStacks {
private:
    std::vector<int> arr;
    std::vector<int> top;
    std::vector<int> next;
    int n, k;
    int freeSlot;

public:
    KStacks(int kStacks, int capacity)
        : arr(capacity), top(kStacks, -1), next(capacity), n(capacity), k(kStacks), freeSlot(0) {
        for (int i = 0; i < n - 1; ++i) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    [[nodiscard]] bool isFull() const { return freeSlot == -1; }
    [[nodiscard]] bool isEmpty(int sn) const {
        assert(sn >= 0 && sn < k);
        return top[sn] == -1;
    }

    bool push(int item, int sn) {
        assert(sn >= 0 && sn < k);
        if (isFull()) {
            return false;
        }
        int i = freeSlot;
        freeSlot = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = item;
        return true;
    }

    int pop(int sn) {
        assert(sn >= 0 && sn < k);
        if (isEmpty(sn)) {
            return -1;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeSlot;
        freeSlot = i;
        return arr[i];
    }
};

int main() {
    int k = 3, n = 6;
    KStacks ks(k, n);

    assert(ks.isEmpty(0));
    assert(ks.isEmpty(1));
    assert(ks.isEmpty(2));

    assert(ks.push(15, 2));
    assert(ks.push(45, 2));
    assert(ks.push(17, 1));
    assert(ks.push(49, 1));
    assert(ks.push(39, 1));
    assert(ks.push(11, 0));
    assert(ks.isFull());
    assert(!ks.push(99, 0)); // Full

    assert(ks.pop(2) == 45);
    assert(ks.pop(1) == 39);
    assert(ks.pop(0) == 11);
    assert(ks.pop(0) == -1); // Now stack 0 is empty

    std::cout << "10_stack_queues 4_Implement_N_stacks_in_an_Array: All tests passed.\n";
    return 0;
}
