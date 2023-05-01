#include <chrono>
#include <iostream>

std::chrono::year_month_day get_ymd(std::string str)
{
    std::istringstream in{str};
    int year, month, day;
    char skip;
    in >> year >> skip >> month >> skip >> day;
    std::chrono::year y(year);
    std::chrono::month m(month);
    std::chrono::day d(day);
    std::chrono::year_month_day tmp(y, m, d);
    return tmp;
}

int main()
{
    std::string str;
    uint64_t sum = 0;
    std::chrono::year_month_day prev{};
    bool not_first = false;
    while (std::cin >> str) {
        if (not_first) {
            auto cur = get_ymd(str);
            const long diff = (std::chrono::sys_days{cur} - std::chrono::sys_days{prev}).count();
            sum += labs(diff);
        }
        not_first = true;
        prev = get_ymd(str);
    }
    std::cout << sum;
}