#include <iostream>
#include <iomanip>

class Point
{
private:
    long long x;
    long long y;
public:
    Point(long long x, long long y) : x(x), y(y) {};
    long long getx()
    {
        return this->x;
    }
    long long gety()
    {
        return this->y;
    }
};

class Line
{
private:
    long long a;
    long long b;
    long long c;
public:
    Line(Point A, Point B)
    {
        a = B.gety() - A.gety();
        b = -(B.getx() - A.getx());
        c = A.getx() * B.gety() - A.gety() * B.getx();
    }
    void friend intersection(Line A, Line B);
};

long long det(const long long a11,const long long a12, const long long a21, const long long a22)
{
    return a11 * a22 - a12 * a21;
}

void intersection(Line A, Line B) {
    double det_A = det(A.a, A.b, B.a, B.b);
    if (det_A == 0) {
        if (det(A.a , A.c, B.a, B.c) == 0 && det(A.b , A.c, B.b, B.c) == 0) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    } else {
        std::cout << 1 << std::endl;
        double y = (-A.c * B.a + B.c * A.a) / det_A;
        double x = (A.c * B.b - B.c * A.b) / det_A;
        std::cout << std::setprecision(10) << x << " " << std::setprecision(10) << y << std::endl;
    }
}

int main() {
    long long x, y;
    std::cin >> x >> y;
    Point A(x, y);
    std::cin >> x >> y;
    Point B(x, y);
    std::cin >> x >> y;
    Point C(x, y);
    std::cin >> x >> y;
    Point D(x, y);
    Line L1(A, B), L2(C, D);
    intersection(L1, L2);
}