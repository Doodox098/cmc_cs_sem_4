#include <iostream>

class A {
    int a;
public:
    int f = 0;
    A() {
        std::cin >> a;
    }
    A(A &b) {
        int c;
        std::cin >> c;
        b.f = 1;
        a = c + b.a;
    }
    ~A() {
        if (f == 0) {
            std::cout << a;
        }
    }
};
