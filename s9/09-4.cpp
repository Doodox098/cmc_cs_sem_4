#include <complex>
#include <vector>
#include <iostream>
#include <array>

namespace Equations
{
    template <typename T>
    std::pair<bool, std::vector<T>> quadratic(std::array<T, 3> v) {
        typedef typename T::value_type v_t;
        v_t EPS = (v_t)32.0 * std::numeric_limits<v_t>::epsilon();
        T a = v[0];
        T b = v[1];
        T c = v[2];
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
            T D = std::sqrt(b * b - (v_t)4.0 * c * a) / (v_t)2.0;
            T res = -b / (v_t)2.0;
            ans.push_back(res + D);
            ans.push_back(res - D);
        }
        return {true, ans};
    }
}
