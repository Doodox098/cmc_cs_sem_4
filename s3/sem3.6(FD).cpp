#include <iostream>
#include <algorithm>
#include <io.h>

using std::cout, std::endl;

class FD
{
    int fd;

public:
    FD(int fd_) : fd(fd_) {}
    ~FD() {close(fd);}
    FD(const FD &other) : fd(dup(other.fd)) {}

    void swap(FD &other)
    {
        std::swap(fd, other.fd);
    }

    FD &operator=(FD tmp) // copy and swap
    {
        swap(tmp);
        return *this;
    }
};

int main()
{
//    FD ff;
    FD f2(dup(0));
    FD f3{f2};

    FD f4{dup(1)};

    f4 = f3;
}