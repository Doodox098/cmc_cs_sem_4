#include <iostream>
#include <algorithm>
#include <unistd.h>

using std::cout, std::endl;

class FD
{
    int fd{-1};

public:
    FD(int fd_) : fd(fd_) {}
    ~FD() {if (fd >=0) close(fd);}
    FD(const FD &other) : fd(dup(other.fd))
    {
        if (fd >= 0) fd = dup(fd);
    }

    FD(FD &&other) noexcept : fd(other.fd)
    {
        other.fd = -1;
    }

    void swap(FD &other) noexcept
    {
        std::swap(fd, other.fd);
    }

    FD &operator=(FD tmp) // copy and swap
    {
        swap(tmp);
        return *this;
    }
};
// strace ./3 >&aaa

int main()
{
    std::vector<FD> fds;
    fds.emplace_back(dup(0));
    fds.emplace_back(dup(1));
    fds.emplace_back(dup(2));

    //std::vector<FD> fds2{fds};
}

// 1) copyable + movable
// 2) movable(std::thread)
// 3) ___ (std::mutex)