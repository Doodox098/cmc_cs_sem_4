#include <iostream>
#include <iomanip>

using std::cin, std::cout, std::hex;

int main()
{
    long long seq_len{1};
    char prev{};
    char cur{};
    cin.get(prev);
    if (std::cin.eof()) {
        exit(0);
    }
    while (cin.get(cur)) {
        if (std::cin.eof()) {
            prev = cur;
            break;
        }
        if (cur == prev) {
            ++seq_len;
        } else {
            if (seq_len > 4 || prev == '#') {
                cout << '#' << prev << hex << seq_len << '#';
            } else {
                for (int i = 0; i < seq_len; ++i) {
                    cout << prev;
                }
            }
            prev = cur;
            seq_len = 1;
        }
    }
    if (seq_len > 4 || prev == '#') {
        cout << '#' << prev << hex << seq_len << '#';
    } else {
        for (int i = 0; i < seq_len; ++i) {
            cout << prev;
        }
    }
}