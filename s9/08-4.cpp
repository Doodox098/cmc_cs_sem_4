#include <complex>
#include <vector>
#include <iostream>
#include <array>

namespace Equations
{
    template <typename T>
    std::pair<bool, std::vector<T>> quadratic(std::array<T, 3> v) {
        typedef typename T::value_type v_t;
        constexpr v_t EPS = (v_t)32.0 * std::numeric_limits<v_t>::epsilon();
        constexpr v_t FOUR = static_cast<v_t>(4.0);
        constexpr v_t TWO = static_cast<v_t>(2.0);
        const T& a = v[2];
        const T& b = v[1];
        const T& c = v[0];
        std::vector<T> ans{};
        if (std::norm(a) < EPS && std::norm(b) < EPS) {
            if (std::norm(c) < EPS)
                return {false, ans};
            else
                return {true, ans};
        }
        if (std::norm(a) < EPS) {
            T res = - c / b;
            ans.push_back(res);
        } else {
            T D = std::sqrt(b * b - FOUR * c * a) / (a * TWO);
            T res = -b / (a * TWO);
            ans.push_back(res + D);
            ans.push_back(res - D);
        }
        return {true, ans};
    }
}

