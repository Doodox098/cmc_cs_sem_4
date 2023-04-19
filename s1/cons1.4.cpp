#include <iostream>

using std::cout, std::cin, std::endl;

void g(int a, int b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(double a, double b)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    g(100, 200);
    g(1.0, 2.0);

    g('a', 20);
    g(1.0, 1.0f);

    //g(1.0, 2); - bad
    g(1, 1L);
    //g(1L, 1L); - bad
}