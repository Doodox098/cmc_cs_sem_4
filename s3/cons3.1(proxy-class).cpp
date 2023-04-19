#include <iostream>
int m[10][10];

struct C
{
    struct R
    {
        C &parent;
        struct T
        {
            R &parent;
        };
        T operator[](size_t index);
    };

    R operator[](size_t index);
};

struct I
{
    II operator,(I, I);
};

int main()
{
    C c;

    /*c[1][2] = ...;
    ... = c[3][3];*/
    c[1, 2];
}