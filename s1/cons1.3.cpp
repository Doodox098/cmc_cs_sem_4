#include <iostream>

using std::cin, std::cout, std::endl;

struct A
{
    A() = default;
    A(int a) { cout << __PRETTY_FUNCTION__ << endl; }
};

struct B
{
    B() = default;

    explicit B(int a)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    operator int()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }

    operator A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return {};
    }
};

void g(A a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void g(int a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void h(A a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void m(...)
{

}

int main() {
    g({});
    g(100);
    g(1L);
    g(A{});
    //g(B{100});
    h(100);
    h('a');
    h(B(100));
}