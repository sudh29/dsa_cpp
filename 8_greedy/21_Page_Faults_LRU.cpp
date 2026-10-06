#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

int pageFaults(int N, int C, const std::vector<int>& pages) {
    std::list<int> lru;
    std::unordered_map<int, std::list<int>::iterator> pos;
    int faults = 0;

    for (int i = 0; i < N; ++i) {
        int page = pages[i];
        if (pos.find(page) == pos.end()) {
            // Page fault
            faults++;
            if (static_cast<int>(lru.size()) == C) {
                int last = lru.back();
                lru.pop_back();
                pos.erase(last);
            }
            lru.push_front(page);
            pos[page] = lru.begin();
        } else {
            // Hit - move to front
            lru.erase(pos[page]);
            lru.push_front(page);
            pos[page] = lru.begin();
        }
    }
    return faults;
}

int main() {
    std::vector<int> pages = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    int C = 4;
    std::cout << "Page faults: " << pageFaults(pages.size(), C, pages) << " (expected 8)\n";
    return 0;
}
