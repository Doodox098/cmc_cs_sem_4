#include <iostream>
#include <vector>
class Matrix
{
private:
    std::vector<std::vector<int>> arr{{0,0,0},{0,0,0},{0,0,0}};
public:
    int& operator[](const int i, const int j) {
        return arr[i][j];
    }
    auto begin() {
        return arr.begin();
    };
    auto end() {
        return arr.end();
    };
};

