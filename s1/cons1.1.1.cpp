#include <iostream>

using std::cin, std::cout, std::endl;

void f(int a, int b) {
    cout << __PRETTY_FUNCTION__  << endl;
}

void g(int a = 10) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << a << endl;

}

void h();

void k(int c, double a = 1.0, int b = {})
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << c << " " << a << " " << b << endl;
}

int main()
{
    f(1, 2);
    g();
    g(2);
    h();

    k(2.2);
    k(0, true);
    k(0, 0, 1LL);
}