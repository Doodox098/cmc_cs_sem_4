#include <memory>
#include <iostream>

using std::cout, std::endl, std::shared_ptr, std::weak_ptr, std::make_shared;

struct A : std::enable_shared_from_this<A> // Currently recurring template pattern
{
    A() { cout << __PRETTY_FUNCTION__ << endl; }
    ~A() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual void g() const { cout << __PRETTY_FUNCTION__ << endl; }

    shared_ptr<A> get() { return shared_from_this(); }
};

struct B : std::enable_shared_from_this<B>
{
};

int main()
{
    auto p1 = make_shared<A>();
    auto p2 = p1->get();
}