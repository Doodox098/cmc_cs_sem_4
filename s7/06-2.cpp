template <typename T, typename F>
T myfilter(T &container, F func)
{
    T res{};
    for (auto &elem: container) {
        if (func(elem)) {
            res.insert(res.end(), elem);
        }
    }
    return res;
}

