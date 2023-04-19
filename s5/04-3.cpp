#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    if (v1.empty())
        return;
    std::vector<int> cp(v1);
    std::sort(cp.begin(), cp.end());
    auto end = cp.end();
    int i = 0;
    cp.erase(std::unique(cp.begin(), cp.end()), end);
    auto it2 = cp.begin();
    while (*it2 < 0) {
        ++it2;
        if (it2 == cp.end())
            return;
    }
    for(auto it1 = v2.begin(); it1 != v2.end(); ++it1, ++i) {
        if (i == *it2) {
            v2.erase(it1);
            ++it2;
            --it1;
            if (it2 == cp.end())
                break;
        }
    }
}
