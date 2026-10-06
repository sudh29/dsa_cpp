#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

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
    assert(pageFaults(static_cast<int>(pages.size()), C, pages) == 8);

    std::vector<int> pages2 = {1, 2, 1, 3};
    assert(pageFaults(static_cast<int>(pages2.size()), 2, pages2) == 3);

    std::cout << "21_Page_Faults_LRU tests passed.\n";
    return 0;
}
