
template <typename T>
T::value_type process(const T &container)
{
    typedef typename T::value_type v_t;
    v_t sum{};
    auto it = container.rbegin();
    if (it == container.rend()) {
        return sum;
    }
    sum += *it;
    ++it;
    if (it == container.rend()) {
        return sum;
    }
    ++it;
    if (it == container.rend()) {
        return sum;
    }
    sum += *it;
    ++it;
    if (it == container.rend()) {
        return sum;
    }
    ++it;
    if (it == container.rend()) {
        return sum;
    }
    sum += *it;
    return sum;
}
