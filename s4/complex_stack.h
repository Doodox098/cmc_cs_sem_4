#include "complex.h"

namespace numbers {
    class complex_stack {
    private:
        complex* stack;
        size_t length;

        complex_stack(const complex_stack& other, complex num) {
            length = other.length + 1;
            stack = new complex[length];
            for (size_t i = 0; i < other.length; ++i) {
                stack[i] = other[i];
            }
            stack[length - 1] = num;
        }

        complex_stack(const complex_stack& other, int num) {
            length = other.length - 1;
            stack = new complex[length];
            for (size_t i = 0; i < other.length - 1; ++i) {
                stack[i] = other[i];
            }
        }

    public:

        complex_stack() {
            length = 0;
            stack = new complex[1];
        }

        complex_stack(const complex_stack& other) : length(other.length){
            stack = new complex[other.length];
            for (size_t i = 0; i < other.length; ++i) {
                stack[i] = other[i];
            }
        }
        ~complex_stack() {
            if (stack != nullptr)
                delete[] stack;
        }
        const complex& operator[](size_t idx) const {
            return stack[idx];
        }
        size_t size() const{
            return length;
        }

        complex operator+() const{
            return stack[length - 1];
        }
        complex_stack operator~() const{
            complex_stack new_complex_stack{*this, -1};
            return new_complex_stack;
        }

        friend complex_stack operator<<(const complex_stack& other, complex num);
        complex_stack& operator=(const complex_stack& other) {
            if (this == &other) {
                return *this;
            }

            length = other.length;
            delete[] stack;
            stack = new complex[other.length];
            for (size_t i = 0; i < other.length; ++i) {
                stack[i] = other[i];
            }
            return *this;
        }

    };
    complex_stack operator<<(const complex_stack& other, complex num) {
        complex_stack new_complex_stack{other, num};
        return new_complex_stack;
    }
}