#include <iostream>
#include <map>
#include <functional>

using std::cout, std::cin, std::endl, std::map, std::pair;

struct cmp
{
    bool operator()(const pair<uint32_t, uint32_t> a, const pair<uint32_t, uint32_t> b) const{
        if (a.first < b.first)
            return true;
        if (a.first > b.first)
            return false;
        if (a.second < b.second)
            return true;
        return false;
    }
};

int main()
{
    constexpr uint32_t MOD = 4294967161;
    map<pair<uint32_t, uint32_t>, uint32_t, cmp> matrix_1;
    map<pair<uint32_t, uint32_t>, uint32_t> matrix_2;
    uint32_t R, C, V;
    while (cin >> R >> C >> V){
        if (V == 0)
            continue;
        if (R == 0 && C == 0 && V == MOD)
            break;
        matrix_1.emplace(std::make_pair(R, C), V);
    }
    while (cin >> R >> C >> V){
        if (V == 0)
            continue;
        if (R == 0 && C == 0 && V == MOD)
            break;
        matrix_2.emplace(std::make_pair(R, C), V);
    }

    for (auto &elem: matrix_2) {
        if (!matrix_1.contains(elem.first)) {
            matrix_1.insert(elem);
        } else {
            uint64_t res = (uint64_t)matrix_1[elem.first] + (uint64_t)elem.second;
            res %= MOD;
            if (res == 0) {
                matrix_1.erase(matrix_1.find(elem.first));
            } else {
                matrix_1[elem.first] = res;
            }
        }
    }
    for (auto &elem : matrix_1) {
        cout << elem.first.first << " " << elem.first.second << " " << elem.second << endl;
    }
}
