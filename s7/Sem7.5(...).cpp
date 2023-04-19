#include <iostream>

using std::cout, std::endl;

template <typename T>
int print(T a)
{
    cout << a << endl;
    return 0;
}
template<typename ...Args>
void f(Args &&...args)
{
    //print(std::forward<Args>(args)...);
    int d[]{print<Args>(args)...};
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename ...Types>
struct S
{
    static constexpr int depth = -1;
};

template<>
struct S<>
{
    static constexpr int depth = 0;
};

template<typename T>
struct S<T>
{
    T f;
    static constexpr int depth = 1;
};

template <typename T, typename ...Other>
struct S<T, Other...>
{
    T f;
    S<Other...> left;
    static constexpr int depth = S<Other...>::depth + 1;

    template <int N>
    T get()
    {
        return left.get<N-1>();
    }

    template <>
    T get<0>()
    {
        return f;
    }
};

int main()
{
    int a{10};
    double b{2.3};
    f<>();
    f<int>(std::move(a));
    f<int, double>(10, 1);

    S<> s1;
    S<double> s2;
    S<int, int, int, int, int, int, int, int, int, int> s3;

    cout << s3.get<1>() << endl;

    cout << s1.depth << endl;
    cout << s2.depth << endl;
    cout << s3.depth << endl;
}