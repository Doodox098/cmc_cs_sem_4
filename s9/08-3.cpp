#include <iostream>


class S {
    int num;
    bool f;
public:
    S() {
        if (!(std::cin >> num))
            f = false;
        else
            f = true;
    }
    S(S &&other) {
        other.f = false;
        num = other.num;
        f = true;
    }
    ~S() {
        if (f)
            std::cout << num << std::endl;
    }
    operator bool () {
        int n;
        if (std::cin >> n) {
            num += n;
            return true;
        }
        return false;
    }
};

