#include <algorithm>

namespace Game
{
    template <typename T>
    class Coord
    {
    public:
        typedef T value_type;
        T row;
        T col;
        Coord(T c1 = T{}, T c2 = T{}) : row{c1}, col{c2} {}
    };
    template <typename T>
    T dist (const Coord<T> size, const Coord<T> a, const Coord<T> b) {
        T dist_x = a.row - b.row + a.col / 2 - b.col / 2;
        T dist_y = a.col - b.col;
        if ((dist_x >= 0 && dist_y >= 0) || (dist_x < 0 && dist_y < 0)) {
            return std::max(std::abs(dist_x), std::abs(dist_y));
        } else {
            return std::abs(dist_x - dist_y);
        }
    }
}
