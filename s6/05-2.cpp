#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::cin, std::cout, std::endl, std::vector, std::map, std::string;

int main()
{
    map<string, vector<int>> students;
    string st;
    int num;
    while (cin >> st >> num){
        if (students.find(st) != students.end()) {
            students[st].push_back(num);
        } else {
            students.insert(std::pair(st, vector<int>{num}));
        }
    }
    for (auto a : students) {
        cout << a.first << ' ';
        double mean = std::accumulate(a.second.begin(), a.second.end(), 0.0) / a.second.size();
        cout << mean << endl;
    }
}