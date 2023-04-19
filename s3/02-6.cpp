#include "StringView.h"
#include <string_view>
#include <string>
#include <iostream>

void f(const StringView& sv)
{
    std::cout << sv[1];
    std::cout << sv.at(1);
}

int main() {
    std::string str{"How much wood would woodchuck chuck if woodchuck could chuck wood?"};
    std::string_view sv{str};
    std::cout << sv.size() << sv.at(55) <<std::endl;
    StringView SV(str, 0);
    std::cout << SV.str() << std::endl;
    std::cout << *SV.begin()<< std::endl;
    std::cout << sv.rend() - sv.rbegin() << std::endl;
    std::cout << SV.at(7) << std::endl;
    StringView::const_iterator it3 = SV.begin();
    StringView::const_reverse_iterator it4 = SV.rbegin();
}