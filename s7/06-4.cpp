#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

template<typename I1, typename I2>
I2 myremove(I1 &&begin_1, I1 &&end_1, I2 &&begin_2, I2 &&end_2)
{
    typedef typename std::iterator_traits<I1>::value_type value_type;
    std::vector<value_type> cp{};
    for (auto it = begin_1; it != end_1; ++it) {
        cp.push_back(*it);
    }
    auto begin_cp = cp.begin();
    auto end_cp = cp.end();
    if (begin_cp == end_cp)
        return end_2;
    std::sort(begin_cp, end_cp);
    int i = 0;
    end_cp = std::unique(begin_cp, end_cp);
    auto it2 = begin_cp;
    while (*it2 < 0) {
        ++it2;
        if (it2 == end_cp)
            return end_2;
    }
    auto er_it = begin_2;
    for(auto it1 = begin_2; it1 != end_2; ++it1, ++i) {
        if (it2 != end_cp && i == *it2) {
            ++it2;
        } else {
            std::swap(*er_it, *it1);
            ++er_it;
        }
    }
    return er_it;
}

