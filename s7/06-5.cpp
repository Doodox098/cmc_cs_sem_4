#include <iterator>
template<typename T>
bool my_comp(T &a, T &b) {
    if (a < b)
        return true;
    return false;
}

template<class RandomIt, class Compare>
void selection_sort(RandomIt first, RandomIt last, Compare comp)
{
    RandomIt d_value;

    for (auto it1 = first; it1 < last; ++it1)
    {
        d_value = it1;
        for (auto it2 = it1 + 1; it2 < last; it2++)
        {
            if (comp(*it2, *d_value))
                d_value = it2;
        }
        if (d_value != it1)
        {
            std::swap(*d_value, *it1);
        }
    }
}

template<class RandomIt>
void selection_sort(RandomIt first, RandomIt last)
{
    selection_sort(first, last, my_comp<typename std::iterator_traits<RandomIt>::value_type>);
}