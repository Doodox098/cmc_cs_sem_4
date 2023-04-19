#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin, std::cout, std::endl;

int main()
{
    double num{};
    double sum{};
    int n{};
    double sqr_sum{};
    double mean{};
    double sqr_deviation{};
    while(cin >> num) {
        if(cin.eof()) {
            break;
        }
        sum += num;
        ++n;
        sqr_sum += num * num;
    }
    mean = sum / n;
    sqr_deviation = std::sqrt((sqr_sum - 2 * mean * sum + std::pow(mean, 2) * n) / n);
    cout << std::setprecision(10) << mean << endl;
    cout << std::setprecision(10) << sqr_deviation << endl;
}