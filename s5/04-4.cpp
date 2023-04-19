#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

class func {
private:
    double sum = 0;
    int n = 0;
public:
    func() = default;
    void operator()(double& num) {
        sum += num;
        ++n;
    }
    double mean() {
        return sum / n;
    }
};

int main()
{
    std::vector<double> nums;
    double num;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    func my_func{};
    size_t k1 = nums.size() / 10;
    std::sort(nums.begin() + static_cast<ssize_t>(k1), nums.end() - static_cast<ssize_t>(k1));
    size_t k2 = k1 + (nums.size() - 2 * k1) / 10;
    my_func = std::for_each(nums.begin() + static_cast<ssize_t>(k2), nums.end() - static_cast<ssize_t>(k2), my_func);
    std::cout << std::setprecision(10) << my_func.mean();
}