
#include <iostream>
class A {
private:
    int f1;
public:
    int f2;
    A() : f1{1}, f2{2}, f3{3}{}
protected:
    int f3;
};

class B {
public:
    B(){std::cout << "B" << std::endl;} // default
    B(int a){std::cout << "B int" << std::endl;} // conversion constructor
    explicit B(double b){std::cout << "B d" << std::endl;};
};

class C {
public:
    C() = default;// = delete
};

int main(){
    A aa;
    A *p = new A;
    std::cout << p->f2;
    B b;
    B b2{10};
    B b3{1.5};
    B b4 = 1.5;
}