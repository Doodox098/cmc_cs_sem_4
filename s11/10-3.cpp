#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sstream>

using std::vector, std::map, std::pair, std::string, std::make_pair;


int main() {
    string rule;
    map<pair<string, char>, string> rules{};
    vector<string> end;
    string from, to;
    char c;
    while (std::getline(std::cin, rule)) {
        if (rule == "END") break;
        std::istringstream in(rule);
        in >> from >> c >> to;
        rules.try_emplace(make_pair(from, c), to);
    }
    while (std::cin >> rule) {
        if (rule == "END") break;
        end.push_back(rule);
    }
    int ans = 1;
    string s;
    string in;
    std::cin >> s >> in;
    int count = 0;
    for (auto &elem : in) {
        if (!rules.contains(make_pair(s, elem))) {
            ans = 0;
            break;
        }
        s = rules[make_pair(s, elem)];
        ++count;
    }
    if (std::find(end.begin(), end.end(), s) == end.end()) {
        ans = 0;
    }
    std::cout << ans << std::endl;
    std::cout << count << std::endl;
    std::cout << s << std::endl;
}