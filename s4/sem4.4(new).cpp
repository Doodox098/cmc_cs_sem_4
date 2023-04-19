#include <iostream>
#include <memory>

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
        cout << __PRETTY_FUNCTION__ << " : " << v << endl;
    }
};


std::unique_ptr<A> f(std::unique_ptr<A> p)
{
    cout << "f: " << p->v << endl;

    return move(p);
}

int main()
{
    A *p = new A;
    delete p;

    std::unique_ptr<A> up(new A(10));

    {
        auto res = f(move(up));
    }
    auto up2 = std::make_unique<A>(100);

    A *p2 = new A[4];
    delete[] p2;

    A *p3 = new A[4]{1, 2, 3, 4};
    delete[] p3;

    std::unique_ptr<A[]> up3(new A[4]{200, 201, 202, 203});
    auto up4 = std::make_unique<A[]>(4);
}