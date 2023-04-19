class C
{
private:

    int b{};
public:
    C(int a, int b) {
        this->b = b;
    }
    C(const C *pC) {
        this->b = pC->b;
    }
    C(C a, C b) {
        this->b = a.b + b.b;
    }
    C(double b) {
        this->b = b;
    }
    C (C const &other) {
        this->b = other.b;
    }
    C() = default;
    friend C operator+(C c2, C c1);
    friend int operator~(C c2);
    friend int operator*(C c2, C* c1);

    C operator++() {
        ++this->b;
        return *this;
    }
};

C operator+(C c2, C c1)
{
    return C(c2.b, c2.b + c1.b);
}

int operator *(C c2, C* c1)
{
    return c2.b * c1->b;
}

int operator~(C c2)
{
    return -c2.b;
}


