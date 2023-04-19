#include <iostream>

int main() {
    std::string s;
    std::cin.tie(nullptr);
    while(getline(std::cin, s)) {
        if(std::cin.eof()) {
            break;
        }
        for (int i = 0; i < int(s.length() - 1); ++i) {
            if (s.at(i) == '0' && isdigit(s.at(i + 1)) && (i == 0 || !isdigit(s.at(i - 1)))) {
                s.erase(s.begin() + i, s.begin() + i + 1);
                --i;
            }
        }
        std::cout << s << std::endl;
    }
}