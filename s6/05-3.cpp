#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

using std::cin, std::cout, std::endl, std::vector, std::map, std::string;

class Date {
private:
    size_t year;
    size_t month;
    size_t day;
public:
    Date(Date const &date) {
        year = date.year;
        month = date.month;
        day = date.day;
    }
    Date(string s) {
        std::istringstream in(s);
        char skip;
        in >> year >> skip >> month >> skip >> day;
    }
    string str() {
        std::ostringstream out("");
        out << year << '/' << std::setfill('0') << std::setw(2)
            << month << '/' << std::setfill('0') << std::setw(2) << day;
        return out.str();
    }
    friend bool operator==(const Date& date1, const Date& date2);
    friend bool cmp(const Date& date1, const Date& date2);
};

bool operator==(const Date& date1, const Date& date2){
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
        return true;
    return false;
}

bool cmp(const Date& date1, const Date& date2){
    if (date1.year < date2.year)
        return true;
    if (date1.year > date2.year)
        return false;
    if (date1.month < date2.month)
        return true;
    if (date1.month > date2.month)
        return false;
    if (date1.day < date2.day)
        return true;
    if (date1.day > date2.day)
        return false;
    return false;
}

int main()
{
    map<std::pair<string, string>, int> students;
    vector<Date> dates;
    vector<string> names;
    size_t max_names = 0;
    string name;
    string date;
    int num;
    while (cin >> name >> date >> num){
        Date cur(date);
        if(std::find(dates.begin(), dates.end(), cur) == dates.end())
            dates.push_back(cur);
        if(std::find(names.begin(), names.end(), name) == names.end())
            names.push_back(name);
        if (name.size() > max_names) {
            max_names = name.size();
        }
        auto new_pair = std::make_pair(name, cur.str());
        if(students.contains(new_pair))
            students[new_pair] = num;
        else
            students.emplace(new_pair, num);
    }

    std::sort(dates.begin(), dates.end(), cmp);
    std::sort(names.begin(), names.end());
    cout << "." << std::setw(max_names - 1) << "";
    for (auto dat : dates) {
        cout << ' ' << dat.str();
    }
    cout << endl;
    for (auto &name : names) {
        cout << name << std::setw(max_names - name.size()) << "";
        for (auto &dat : dates) {
            std::pair<string, string> n_p(name, dat.str());
            if (students.find(n_p) != students.end()) {
                cout << " " << students[n_p] << std::setw(dat.str().size() - 1) << "";
            } else {
                cout << " ." << std::setw(dat.str().size() - 1) << "";
            }
        }
        cout << endl;
    }
}