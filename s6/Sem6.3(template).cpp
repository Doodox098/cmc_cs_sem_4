#include <iostream>

using std::cout, std::endl;

auto inc(auto x) {cout << __PRETTY_FUNCTION__ << endl ; return x + 1;}
auto inc2(auto x, auto y) {cout << __PRETTY_FUNCTION__ << endl ; return x + y + 1;}

template<typename T>
T inc3(T x, T y, T z)
{
    cout << __PRETTY_FUNCTION__ << endl ;
    return x + y + z;
}

template<>
char inc3(char x, char y, char z)
{
    cout << __PRETTY_FUNCTION__ << " {} " << endl;
    return 'a';
}

int main()
{
    int a = 1;
    double b = 20;
    long long c = 100;

    cout << inc(a) << endl;
    cout << inc(b) << endl;
    cout << inc(c) << endl;

    cout << inc2(a, c) << endl;
    cout << inc2(c, b) << endl;

    cout << inc3<bool>(a, b, c) << endl;
    cout << inc3(a, a, a) << endl;
    cout << inc3((char) a, (char)b, (char)c) << endl;
}