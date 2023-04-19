#include <vector>

using std::vector;
struct NC
{
    NC() {}

    NC(const NC &other) = delete;
    NC(const NC &&other) = default;
};

int main()
{
    vector <NC> v;
    //v.push_back(NC());
}