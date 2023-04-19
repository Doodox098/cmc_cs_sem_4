#include <iostream>

using std::cin, std::cout, std::endl;


struct A
{
    static int b;

    void f() // A* this
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    static void g()
    {
        ++b;
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main() {
    A a;
    A a2;
    a.f();
    a.g();
    a2.g();
    A::g();
}