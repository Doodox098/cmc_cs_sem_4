#include <iostream>

int main()
{
    int c;
    int mode = -1;
    while ((c = std::getchar()) != EOF)
    {
        if (c == '0') {
            if (mode == -1) {
                mode = 0;
            } else if (mode == 1) {
                std::putchar(c);
            }
        } else if (std::isdigit(c)) {
            mode = 1;
            std::putchar(c);
        } else {
            if (mode == 0) {
                std::putchar('0');
            }
            mode = -1;
            std::putchar(c);
        }
    }

    if (mode == 0) {
        std::putchar('0');
    }
}