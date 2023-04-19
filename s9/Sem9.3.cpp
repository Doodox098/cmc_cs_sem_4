#include <any>
#include <map>
#include <string>
#include <iostream>

using std::cin, std::cout, std::endl;
using std::any, std::string, std::map;

int main()
{
    map<string, any> j;
    j["1"] = std::make_any<int>(10);
    j["2"] = std::make_any<bool>(true);
    j["3"] = std::make_any<string>("true");
    j["3"] = std::make_any<map<string, any>>(j);
    for (const auto &p : j) {
        if (const auto &t = p.second.type(); t == typeid(int)) {
            cout << "int: " << any_cast<int>(p.second) << endl;
        } else if (t == typeid(bool)) {
            cout << "bool: " << any_cast<bool>(p.second) << endl;
        }
    }
}