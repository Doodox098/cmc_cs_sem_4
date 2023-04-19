#include <iostream>

using std::cout, std::endl;

class Array
{
    static constexpr int N = 10;


    double data[N]{};

public:

    double &operator [](size_t i) { return data[i]; }
    double operator [](size_t i) const { return data[i];}
    size_t size() const { return N; }
};

// ssize_t

void f(const Array &a)
{
    std::cout << a[0] << std::endl;
}


int main()
{
    Array a1;

    a1[0] = 1.0;
    f(a1);

    cout << std::ssize(a1) << endl;

//    for (size_t i = a1.size() - 1; i >= 0; --i) {
//    }
    for (ssize_t i = std::ssize(a1) - 1; i >= 0; --i) {
    }
}
