//#include "eval.h"
#include <iostream>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


int main(int argc, char **argv)
{
    enum {
        BASE = 10,
    };
    numbers::complex C(argv[1]);
    double R = strtod(argv[2], nullptr);
    int N = strtol(argv[3], nullptr, BASE);
    numbers::complex I(0,0);
    std::vector<std::string> func;
    for (int i = 4; i < argc; ++i) {
        func.emplace_back(argv[i]);
    }
    double a = -M_PI;
    for (int i = 0; i < N; ++i) {
        numbers::complex z = numbers::complex(R * cos(a), R * sin(a)) + C;
        numbers::complex ev = numbers::eval(func, z);
        numbers::complex dz = numbers::complex(R * cos(a), R * sin(a)) * 2 * M_PI / N * numbers::complex(0, 1);
        I += ev * dz;
        a += (2 * M_PI / N);
    }
    std::cout << I.to_string() << std::endl;
}

