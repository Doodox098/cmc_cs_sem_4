#include <iostream>
#include <iomanip>

struct point {
    long long _x, _y;

    point(long long x, long long y) : _x(x), _y(y) {};
};

struct line {
    long long a, b, c;

    line(point p1, point p2) {
        a = p2._y - p1._y;
        b = -(p2._x - p1._x);
        c = p1._x * p2._y - p2._x * p1._y;
    };
};

void itr(line l1, line l2, long long det) {
    double x, y;
    y = (-l2.a * l1.c + l1.a * l2.c) /(double)det;
    x = (l2.b * l1.c -l1.b * l2.c)/(double)det;
    std::cout << 1 << std::endl;
    std::cout << std::setprecision(6) << x << " " << std::setprecision(6) << y << std::endl;
}

long long deter(line l1, line l2) {
    return l1.a * l2.b - l1.b * l2.a;
}



int main() {
    long long x1, x2, y1, y2, x3, x4, y3, y4;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    point p1 = point(x1, y1);
    point p2 = point(x2, y2);
    point p3 = point(x3, y3);
    point p4 = point(x4, y4);
    line l1 = line(p1, p2);
    line l2 = line(p3, p4);
    long long det = deter(l1, l2);
    if (det == 0) {
        if (l1.a * l2.c - l1.c * l2.a == 0 && l1.b * l2.c - l2.b * l1.c == 0) {
            std::cout << 2 << std::endl;
            exit(0);
        } else {
            std::cout << 0 << std::endl;
            exit(0);
        }
    }

    itr(l1, l2, det);
}