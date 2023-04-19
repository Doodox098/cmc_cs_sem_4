#include <string>
#include <iostream>

using std::cout, std::endl, std::string;

struct A
{
    string name;

    A(const string &s) : name(s) {}
};
struct B
{
    string name;

    B(string s) : name(std::move(s)) {}
};
int main()
{
    A a("123");
    string s("123");
    A a2(s);
    B b("123");
    B b2(s);
    B b3(std::move(s));
}