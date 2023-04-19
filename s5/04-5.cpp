#include <iostream>
#include <list>

using std::cin, std::cout, std::endl, std::list;

int main()
{
    list<int> numbers;
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        numbers.push_back(num);
    }
    if (num == 0) {
        int64_t x, y;
        while (cin >> x) {
            if (x < 0) {
                uint64_t er = -x - 1;
                if (er >= numbers.size()) {
                    continue;
                }
                auto it = numbers.begin();
                std::advance(it, er);
                numbers.erase(it);
            } else {
                cin >> y;
                auto it = numbers.begin();
                uint64_t er = std::min(x - 1, (int64_t) numbers.size());
                std::advance(it, er);
                numbers.insert(it, y);
            }
        }
    }
    for (auto &elem : numbers) {
        cout << elem << endl;
    }
    numbers.clear();
}