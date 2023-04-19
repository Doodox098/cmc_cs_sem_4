#include <string>
#include <iostream>

using std::string;

class BinaryNumber
{
private:
    string num ;
public:
    BinaryNumber(const string &s){
        num = s;
    }
    operator string () const
    {
        return num;
    }
    const BinaryNumber &operator++(){
        int old = 1;
        for (auto a = num.end() - 1; a >= num.begin(); --a)
        {
            if (old == 1) {
                if (*a == '0') {
                    num.replace(a, a + 1, "1");
                    old = 0;
                } else {
                    num.replace(a, a + 1, "0");
                }
            }
        }
        if (old) {
            num.insert(0, "1");
        }
        return *this;
    }
};

