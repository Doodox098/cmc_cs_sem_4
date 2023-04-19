#include <memory>
#include <iostream>

using std::cout, std::endl, std::shared_ptr, std::weak_ptr, std::make_shared;

struct A
{
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void g() const {cout << __PRETTY_FUNCTION__ << endl; }
};

int main()
{
    auto p1 = make_shared<A>();
    auto p2 = make_shared<A>();

    {
        weak_ptr<A> w1(p1);
        // w1->g()
        if (auto p3 = w1.lock(); p3) {
            p3->g();
        }
        weak_ptr<A> w2(p2);

        p2.reset();
        p2->g();

        if (auto p3 = w2.lock(); p3) {
            p3->g();
        } else {
            cout << nullptr << endl;
        }
    }
}