#include <sstream>
#include <cmath>

#include "07-1.cpp"

class Rectangle: public Figure
{
private:
    double a;
    double b;
public:
    std::string to_string() {
        std::ostringstream o;
        o << "R " << a << " " << b;
        return o.str();
    }
    double get_square() const override {
        return a * b;
    }
    static Rectangle* make(const std::string s) {
        std::istringstream in(s);
        Rectangle* Rec = new Rectangle;
        in >> Rec->a >> Rec->b;
        return Rec;
    }
};

class Square: public Figure
{
private:
    double a;
public:
    std::string to_string() {
        std::ostringstream o;
        o << "S " << a;
        return o.str();
    }
    double get_square() const override {
        return a * a;
    }
    static Square* make(const std::string s) {
        std::istringstream in(s);
        Square* Sqr = new Square;
        in >> Sqr->a;
        return Sqr;
    }
};

class Circle: public Figure
{
private:
    double r;
public:
    std::string to_string() {
        std::ostringstream o;
        o << "C " << r;
        return o.str();
    }
    double get_square() const override {
        return M_PI * r * r;
    }
    static Circle* make(const std::string s) {
        std::istringstream in(s);
        Circle* Cir = new Circle;
        in >> Cir->r;
        return Cir;
    }
};