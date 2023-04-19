#include <iostream>

int main() {
    char next;
    char cur;
    char prev{'\0'};
    std::cin.tie(nullptr);
    std::cin.get(cur);
    while(std::cin.get(next)) {
        if(std::cin.eof()) {
            break;
        }
        if (cur != '0') {
            std::cout << cur;
            prev = cur;
        } else if (!isdigit(next) || isdigit(prev)) {
            std::cout << cur;
            prev = cur;
        }
        cur = next;
    }
    std::cout << cur;
}
