#include <iostream>
using std::cout, std::endl, std::cin;

int main()
{
    std::string str{};
    while (cin >> str) {
        auto b = str.begin();
        while(b != str.end() && (*b == '3' || *b == '4')) {
            ++b;
        }
        while(b != str.end() && (*b == '1' || *b == '2')) {
            ++b;
        }
        if (b == str.end()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}