// Лекции в записи
#include <iostream>
#include <iomanip>

#include <cstdio>

//using namespace std; не использовать

namespace A
{
    int b;
    double c;
    namespace B
    {
        long d;
    }
}

namespace A::B
{
    char e;
}

namespace
{
    long g;// недоступно извне
}

long long f;

int mn() {
    std::cin >> ::g >> f;
}

constexpr int N = 10; // константа компиляции
int m[N];

constexpr int func(int n) {
    int res = 1;
    for (int i = 2; i < n; ++i) {
        res *= i;
    }
    return res;
}

auto a = 100;
auto b = 'c';
auto c = "11";

int main(int argc, char *argv[]) {
    /*
    int a = 0;
    int c(0); //c98
    int d{0}; //uniform initializer наш выбор
    int e{}; //инициализация 0
    int f(2.0);
    // int g{2.0}; // narrowing conversion

    // most vexing parse

    [[maybe_unused]] //аннотация
    int b;

    using tt = int;

    tt aa;

    using std::cin;

    cin >> a >> b;

    using std::cout, std::endl;
    cout << a << endl; // endl = "\n" + fflush(stdout)
    std::cout << std::dec << std::setfill('0') << std::setw(10) << a + b << std::endl;
    */
    char c;
    /*std::cin >> std::noskipws;//не скипать пробелы
    while(std::cin >> c) {
        std::cout << int{c} << std::endl;
    }*/
    while(std::cin.get(c)) {
        std::cout << int{c} << std::endl;
    }
}

// c и c++ плохо стыкуются из-за различий в именовании
