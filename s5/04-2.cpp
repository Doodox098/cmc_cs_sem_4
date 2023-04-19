#include <string>
#include <vector>
#include <iostream>


void process(std::vector<long int> &v1, long int step)
{
    v1.reserve(v1.size() * 2);
    auto it1 = v1.rbegin();
    while (it1 != v1.rend())
    {
        if (*it1 >= step) {
            v1.push_back(*it1);
        }
        it1++;
    }
}
