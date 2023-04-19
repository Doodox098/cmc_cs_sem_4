#include <iostream>
using std::cout, std::endl, std::cin;


int main()
{
    int ans = 23;
    bool term = true;
    bool sr = true;

    std::string left{}, right{};
    while (cin >> left >> right) {
        if (left == "S") {
            sr = false;
        }
        for (auto &elem : left) {
            if (std::isupper(elem)) {
                term = false;
            }
        }
    }
}