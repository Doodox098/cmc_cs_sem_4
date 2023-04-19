#include <iostream>
#include <exception>
#include <utility>

class my_ex : std::exception {
private:
    std::string str;
    bool f;
public:
    my_ex(std::string s) : str(std::move(s)), f(true){};
    my_ex() : f(false){};
    ~my_ex() override{
        if (f && str != "")
            std::cout << str << std::endl;
    }
};

void rw () {
    std::string str{};
    std::cin >> str;
    if (std::cin.eof()) {
        throw my_ex(str);
    }
    try {
        rw ();
    } catch (...) {}
    throw my_ex(str);
}

int main()
{
    try {
        rw();
    } catch (...) {
    }
}