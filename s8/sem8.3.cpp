#include <iostream>
#include <memory>

using std::cout, std::endl, std::make_unique, std::unique_ptr;

struct A
{
    virtual void f(int x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct B
{
    void f(double)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

struct C : A, B
{
    using A::f, B::f;
    void g()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main()
{
    C c;
    c.g();
    //c.f(1);
    c.A::f(1);
    c.B::f(1);
    c.f(1);
    c.f(1.2);
}