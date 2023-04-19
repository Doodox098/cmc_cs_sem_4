#include <iostream>

using std::cout, std::endl;

struct A
{
    void f(int x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct B : public A
{
    void f(double x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct C : public A
{
    using A::f;
    void f(double x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};
int main()
{
    A a;
    B b;
    C c;

    a.f(100);
    a.f(1.2);

    b.f(100);
    b.f(1.2);

    c.f(100);
    c.f(1.2);
}