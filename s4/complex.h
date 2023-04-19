#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

namespace numbers {
    class complex {
    private:
        double _re{};
        double _im{};
    public:
        complex() {};

        complex(double _re) : _re(_re) {};

        complex(double _re, double _im) : _re(_re), _im(_im) {};

        explicit complex(const std::string &s) {
            _re = std::stod(s.substr(1, s.find(',') - 1));
            _im = std::stod(s.substr(s.find(',') + 1, s.length() - (s.find(',') + 1) - 1));
        }

        double re() const{ return _re; };

        double im() const{ return _im; };

        double abs2() const{
            return std::pow(_re, 2) + std::pow(_im, 2);
        }

        double abs() const{
            return std::sqrt(abs2());
        }

        std::string to_string() const {
            std::ostringstream strs;
            strs << "(" <<std::setprecision(10) << _re << "," << std::setprecision(10) << _im << ")";
            return strs.str();
        }

        complex operator+=(complex CN) {
            this->_re += CN._re;
            this->_im += CN._im;
            return *this;
        }

        complex operator-=(complex CN) {
            this->_re -= CN._re;
            this->_im -= CN._im;
            return *this;
        }

        complex operator*=(complex CN) {
            double n_re = this->_re * CN._re - this->_im * CN._im;
            double n_im = this->_re * CN._im + this->_im * CN._re;
            this->_re = n_re;
            this->_im = n_im;
            return *this;
        }

        complex operator/=(complex CN) {
            double n_re = (this->_re * CN._re + this->_im * CN._im) / CN.abs2();
            double n_im = (this->_im * CN._re - this->_re * CN._im) / CN.abs2();
            this->_re = n_re;
            this->_im = n_im;
            return *this;
        }

        complex operator~() const{
            return {_re, -_im};
        }

        complex operator-() const{
            return {-_re, -_im};
        }
    };
    numbers::complex operator +(numbers::complex CN1, numbers::complex CN2) {
        return CN1 += CN2;
    }
    numbers::complex operator -(numbers::complex CN1, numbers::complex CN2) {
        return CN1 -= CN2;
    }
    numbers::complex operator *(numbers::complex CN1, numbers::complex CN2) {
        return CN1 *= CN2;
    }
    numbers::complex operator /(numbers::complex CN1, numbers::complex CN2) {
        return CN1 /= CN2;
    }
}