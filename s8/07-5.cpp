
#include <string>
#include <iostream>

class Figure
{
public:
    virtual ~Figure() {};
    virtual bool equals(Figure* f2) const = 0;
};

class Rectangle: public Figure
{
private:
    double a;
    double b;
public:
    Rectangle(const int &h, const int &w) {
        a = h;
        b = w;
    }
    bool equals(Figure *f2) const override {
        auto f = dynamic_cast<const Rectangle*>(f2);
        if (f == nullptr)
            return false;
        return (this->a == f->a && this->b == f->b);
    }
};

class Triangle: public Figure
{
private:
    double a;
    double b;
    double c;
public:
    Triangle(const int &a1, const int &a2, const int &a3) {
        a = a1;
        b = a2;
        c = a3;
    }
    bool equals(Figure *f2) const override {
        auto f = dynamic_cast<const Triangle*>(f2);
        if (f == nullptr)
            return false;
        return (this->a == f->a
        && this->b == f->b
        && this->c == f->c);
    }
};

