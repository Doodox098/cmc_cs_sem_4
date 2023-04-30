
#include <string>
#include <iostream>

class Figure
{
public:
    virtual ~Figure() = default;
    virtual bool equals(const Figure* f2) const = 0;
};

class Rectangle: public Figure
{
private:
    int a;
    int b;
public:
    Rectangle(const int h, const int w) : a(h), b(w) {}
    bool equals(const Figure *f2) const override {
        const Rectangle *f = dynamic_cast<const Rectangle*>(f2);
        if (f == nullptr)
            return false;
        return this->a == f->a && this->b == f->b;
    }
};

class Triangle: public Figure
{
private:
    int a;
    int b;    int c;
public:
    Triangle(const int a1, const int a2, const int a3) : a(a1), b(a2), c(a3) {}
    bool equals(const Figure *f2) const override {
        const Triangle *f = dynamic_cast<const Triangle*>(f2);
        if (f == nullptr)
            return false;
        return this->a == f->a
            && this->b == f->b
            && this->c == f->c;
    }
};

