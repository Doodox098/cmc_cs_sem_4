#include <iostream>
using std::cout, std::endl, std::cin;

int main()
{
    std::string str{};
    while (cin >> str) {
        std::string tmpl = "";
        std::string cmp = "";
        int ans = 1;
        auto b = str.begin();
        if (b != str.end() && *b != '0') {
            cout << 0 << endl;
            continue;
        }
        while(b != str.end() && *b == '0') {
            tmpl.push_back(*b);
            ++b;
        }
        if (b == str.end() || *b != '1') {
            cout << 0 << endl;
            continue;
        }
        while(b != str.end() && *b == '1') {
            tmpl.push_back(*b);
            ++b;
        }
        if (b != str.end() && *b != '0') {
            cout << 0 << endl;
            continue;
        }
        size_t i = 0;
        if (str.length() % tmpl.length()) {
            cout << 0 << endl;
            continue;
        }
        while(i < str.length()) {
            cmp = str.substr(i, tmpl.length());
            if (cmp != tmpl) {
                ans = 0;
            }
            i += cmp.length();
        }
        cout << ans << endl;
    }
}