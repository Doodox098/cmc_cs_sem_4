#include <iostream>

class Sum
{
    int a;
public:
    Sum(Sum a, int b) : a{a.a + b} {};
    Sum(int a, int b)  : a{a + b} {};
    int get() const{
        return a;
    }
};

