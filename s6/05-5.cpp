#include <iostream>
#include <map>
#include <vector>
#include <functional>

using std::cout, std::cin, std::endl, std::map, std::pair, std::vector;

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
    map<uint32_t, map<uint32_t, uint32_t>> matrix_1;
    map<pair<uint32_t, uint32_t>, uint32_t, cmp> res_matrix;
    uint32_t R, C, V;
    while (cin >> R >> C >> V){
        if (V == 0)
            continue;
        if (R == 0 && C == 0 && V == MOD)
            break;
        if (matrix_1.contains(C))
            matrix_1[C].emplace(R, V);
        else {
            map<uint32_t, uint32_t> new_row{std::make_pair(R, V)};
            matrix_1.emplace(C, new_row);
        }
    }
    while (cin >> R >> C >> V){
        if (V == 0)
            continue;
        if (matrix_1.contains(R)) {
            for (auto &elem : matrix_1[R]) {
                auto n_p = std::make_pair(elem.first, C);
                if (res_matrix.contains(n_p)) {
                    uint64_t res = (uint64_t) res_matrix[n_p] + (uint64_t) elem.second * V ;
                    res %= MOD;
                    res_matrix[n_p] = res;
                } else {
                    uint64_t res = (uint64_t) elem.second * V;
                    res %= MOD;
                    res_matrix.emplace(n_p, res);
                }
                if (res_matrix[n_p] == 0) {
                    res_matrix.erase(res_matrix.find(n_p));
                }
            }
        }
    }
    for (auto elem : res_matrix) {
        cout << elem.first.first << " " << elem.first.second << " " << elem.second << endl;
    }
}