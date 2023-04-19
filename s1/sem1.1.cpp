#include <iostream>

const int A1 = 10;
static const int A2 = 20;

namespace
{
    const int A3 = 30;
}
namespace A
{
    const int A4 = 40;
}

int main()
{
    using std::cout, std::endl;

    char a1[A1];
    cout << sizeof(a1) << endl;
}