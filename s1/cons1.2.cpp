#include <iostream>

using std::cin, std::cout, std::endl;

void g(int a) {
    cout << __PRETTY_FUNCTION__  << endl;
}

void g(char a) {
    cout << __PRETTY_FUNCTION__  << endl;
}

void g(const char *a) {
    cout << __PRETTY_FUNCTION__  << endl;
}

int main() {
    g('0');
    g(48);

    unsigned char c = '0';
    g(c);

    short s = 48;
    g(s);

    unsigned int ui = 48;
    g(ui);

    long l = 1;
    g(static_cast<long long>(l));

    g("assa");

    char *p = new char[10]{"12121"};
    g(p);
}