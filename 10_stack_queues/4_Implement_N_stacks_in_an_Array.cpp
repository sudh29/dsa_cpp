#include <iostream>
#include <vector>

using namespace std;

class KStacks {
private:
    int *arr;
    int *top;
    int *next;
    int n, k;
    int freeSlot;

public:
    KStacks(int k1, int n1) : n(n1), k(k1), freeSlot(0) {
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++) top[i] = -1;
        for (int i = 0; i < n - 1; i++) next[i] = i + 1;
        next[n - 1] = -1;
    }

    ~KStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

    bool isFull() { return freeSlot == -1; }
    bool isEmpty(int sn) { return top[sn] == -1; }

    void push(int item, int sn) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        int i = freeSlot;
        freeSlot = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = item;
    }

    int pop(int sn) {
        if (isEmpty(sn)) return -1;
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeSlot;
        freeSlot = i;
        return arr[i];
    }
};

int main() {
    int k = 3, n = 10;
    KStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
    ks.push(11, 0);

    cout << "Popped from stack 2: " << ks.pop(2) << endl;
    cout << "Popped from stack 1: " << ks.pop(1) << endl;
    cout << "Popped from stack 0: " << ks.pop(0) << endl;
    return 0;
}
