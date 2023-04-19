#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

struct A
{
    int a{};
    A(int aa) : a(aa) {};

    A operator+(A a2) const{
        return A(a + a2.a);
    }
};

A operator*(A a1, A a2) {
    return A(a1.a * a2.a);
}

int main() {
    int a = 100;
    int b = 200;
    cout << a + b << endl;
    cout.operator<<(a + b);
    string s{"123\n"};
    operator<<(cout, s);

    A a1{1}, a2{10}, a3{100};
    auto a4 = a1.operator+(a2);
    cout << a4.a << endl;
    auto a5 = a2 + a3;
    cout << a5.a << endl;
    cout << (a1 + a3).a << endl;

    cout << operator*(a1, a2).a << endl;

    auto a6 = a5 + 100;
    auto a7 = (A)100 + a5;
}