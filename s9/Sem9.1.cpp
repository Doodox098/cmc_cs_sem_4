#include <iostream>
#include <cstring>
#include <memory>

using std::cout, std::cin, std::endl;
using std::unique_ptr;

struct A
{
    char *ptr1{};
    char *ptr2{};

    A(const char *p1, const char *p2) : ptr1(new char[strlen(p1) - 1]),
                                        ptr2(new char[strlen(p2) - 1]) // no exception safety
    {
    }
    ~A()
    {
        delete[] ptr1;
        delete[] ptr2;
    }
};

struct B
{
    char *ptr1{};
    char *ptr2{};

    B(const char *p1, const char *p2) try : ptr1(new char[strlen(p1) - 1]),
                                            ptr2(new char[strlen(p2) - 1]){}
    catch (...) {
        delete[] ptr1;
        delete[] ptr2;
        throw;
    }
    ~B()
    {
        delete[] ptr1;
        delete[] ptr2;
    }
};

struct C
{
    unique_ptr<char[]> ptr1;
    unique_ptr<char[]> ptr2;
    C(const char *p1, const char *p2)
    : ptr1(new char[strlen(p1) - 1]),
    ptr2(new char[strlen(p2) - 1]){}
};