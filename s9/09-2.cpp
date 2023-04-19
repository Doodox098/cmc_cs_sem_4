// функция принимает a, b, k и в зависимости от значений либо выбрасывет исключение
// либо вызывает рекурсивно функцию от новых значений
#include <iostream>
#include <exception>

struct Result :std::exception {
    int64_t res;
    Result(int64_t num) : res(num){}
    void print() {
        std::cout << res << std::endl;
    }
};

void func (int64_t a, int64_t b, uint32_t k) {
    if (k == 0) {
        throw Result(a + b);
    } else if (b == 1) {
        throw Result(a);
    }
    try {
        func(a, b - 1, k);
    } catch (Result &e) {
        b = e.res;
    }
    func(a, b, k - 1);
}

int main()
{
    int64_t a;
    int64_t b;
    uint32_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result &e) {
            e.print();
        }
    }
}