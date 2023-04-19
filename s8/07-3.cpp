#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>



using std::cin, std::istringstream, std::getline, std::vector, std::cout, std::endl;

class Figure_make
{
private:
    Figure_make() {};

public:
    static Figure_make &factory_instance() {
        static Figure_make f;
        return f;
    }
    static Figure *make(std::string dec) {
        istringstream i(dec);
        char type;
        i >> type;
        if (type == 'R') {
            getline(i, dec);
            return Rectangle::make(dec);
        }
        if (type == 'S') {
            getline(i, dec);
            return Square::make(dec);
        }
        if (type == 'C') {
            getline(i, dec);
            return Circle::make(dec);
        }
        return nullptr;
    }
};

bool cmp(const Figure *a, const Figure *b) {
    return (a->get_square() < b->get_square());
}

int main() {
    vector<Figure*> figures{};
    std::string s;
    while (getline(cin, s)) {
        figures.push_back(Figure_make::make(s));
    }
    std::stable_sort(figures.begin(), figures.end(), cmp);
    for (auto elem : figures) {
        cout << elem->to_string() << endl;
        delete elem;
    }
}