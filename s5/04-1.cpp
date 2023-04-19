#include <string>
#include <vector>
#include <iostream>


void process(const std::vector<long unsigned int> &v1, std::vector<long unsigned int> &v2, unsigned int step)
{
    auto it1 = v1.begin();
    if (it1 == v1.end()) {
        return;
    }
    auto it2 = v2.rbegin();
    while(it1 != v1.end() and it2 != v2.rend())
    {
        *it2 += *it1;
        it2++;
        for (unsigned int i = 0; i < step; i++)
        {
            it1 += 1;
            if (it1 == v1.end()) {
                return;
            }
        }
    }
}
