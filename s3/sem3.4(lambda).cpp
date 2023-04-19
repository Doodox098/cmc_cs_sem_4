#include <iostream>
#include <algorithm>

using std::cout, std::endl;
namespace f {
    auto f() {
        int x = 100;
        return [&x]() { cout << x++ << endl; };
    }
}

int main()
{
    int a[]{ 5, 4, 2, 1, 0 };
    std::sort(a, a + 5, [](auto a, auto b) -> bool { return a < b;});
    for (auto v : a) {
        cout << v << endl;
    }

    cout << [](auto a) { cout << a + 1 << endl; return a - 1;}(a[0]) << endl;
    auto f = [] { cout << "hehe" << endl; };
    f();
    int b = 100;
    auto f1 = [a=a[0], b]() { cout << a << ' ' << b <<endl; };
    f1();
    auto f2 = [&b]() { cout << b++ << endl; };
    f2();
    cout << b << endl;
    auto f3 = [=]() { cout << b << endl; };
    auto f4 = [&]() { cout << b++ << endl; };
    f3();
    f4();
    cout << b << endl;
    f::f()();
}