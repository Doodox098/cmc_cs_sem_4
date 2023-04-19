#include <iostream>

using std::cout, std::endl;

struct A
{
    int v{};

    A(int vv = 0) : v(vv)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~A()
    {

        cout << __PRETTY_FUNCTION__ << ":" << v << endl;
    }
};

int main()
{
    A a;

    new (&a) A(101);
    a.~A();

    unsigned char *p = new unsigned char[2*sizeof(A)];

    auto p1 = new (p) A(1000);
    auto p2 = new (p + sizeof(A)) A(1001);

    p1->~A();
    p2->~A();
}