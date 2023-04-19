#include <vector>
template<typename I, typename F>
void myapply(I ib, I ie, F func)
{
    while(ib != ie) {
        func(*ib);
        ++ib;
    }
}

template<typename I, typename F>
std::vector<std::reference_wrapper<typename std::iterator_traits<I>::value_type>>
myfilter2(I ib, I ie, F func)
{
    std::vector<std::reference_wrapper<typename std::iterator_traits<I>::value_type>> res;

    while(ib != ie) {
        if (func(*ib)) {
            res.push_back(*ib);
        }
        ++ib;
    }
    return res;
}

