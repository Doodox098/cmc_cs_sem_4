#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout, std::endl, std::vector;

int count_ones(uint32_t a){
    int cnt = 0;
    while (a > 0) {
        if (a & 1) ++cnt;
        a >>= 1;
    }
    return cnt;
}

bool cmp(const uint32_t &a, const uint32_t &b) {
    int cnt1 = count_ones(a);
    int cnt2 = count_ones(b);
    if (cnt1 < cnt2)
        return true;
    return false;
}
int main()
{
    vector<uint32_t> nums{};
    uint32_t num;
    while(cin >> num)
    {
        nums.push_back(num);
    }
    std::stable_sort(nums.begin(), nums.end(), cmp);
    for (auto a : nums)
    {
        cout << a << endl;
    }
}