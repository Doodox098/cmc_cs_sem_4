#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>

using std::cout, std::endl, std::cin, std::vector, std::list, std::pair, std::string, std::map;

// 1: (T) v
// 2: T(v) T{v}
// 3: static_cast:
//      double->int
//      int->char
//      bool->double
//      void* -> T*
//      nullptr_t -> T*
//
//      Base* -> Derived*
//      Base& -> Derived&
// 4: const_cast
//      const T& -> T&
//      const T* -> T*
//      volatile T -> T
// 5: reinterpret_cast
//      int -> T*
//      T* -> int
//      A* -> B*
// 6: dynamic_cast
//      Base* -> Derived*
//      Base *b
//      dynamic_cast<Derived*>(b)
//          if (is_class_or_derived<Derived*>(b)) {
//              static_cast<Derived*>(b)
//          } else {
//              nullptr
//              // В случае ссылок:
//              exception(std::bad_cast)
//          }

class A
{
public:
    virtual ~A() {}
    virtual void add (A*) = 0;
};

class B : public  A
{
    virtual void add(B*) override
    {

    }
};