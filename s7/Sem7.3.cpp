#include <iostream>

template<typename T1, typename T2>
struct S
{
    T1 t1;
    T2 t2;

    static constexpr bool value = false;
};

template<typename T1>
struct S<T1, double>
{
    T1 t1;
    double t2;

    static constexpr bool value = true;
};

int main()
{
    S<double, double> s1;
    S<int, int> s2;

    std::cout <<  s1.value << std::endl;
    std::cout <<  s2.value << std::endl;
}