#include <iostream>
#include <expected>

using std::pair, std::cout, std::endl;
using std::cin;

/*pair<int, bool> f(int a)
{
    if (a > 0) return { a - 1, true };
    return { 0, false };
}

int main()
{
    int x;
    while (cin >> x) {
        if (auto [value, ok] = f(x); ok) {
            cout << "result " << value << endl;
        } else {
            cout << "error" << endl;
        }
    }
}*/
// std::optional
std::expected<int, const char *> f(int a)
{
    if (a > 0) return { a - 1 };
    return std::unexpected("fail");
}

int main()
{
    int x;
    while (cin >> x) {
        if (auto r = f(x); r) {
            cout << "result " << *r << endl;
        } else {
            cout << "error" << r.error() << endl;
        }
    }
}