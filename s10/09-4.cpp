// S->aAd
// A -> aAd | bBc
// B -> bBc | eps

#include <iostream>
using std::cout, std::endl, std::cin;

void S(int k, int n) {
    if (k == 0) {
        return;
    } if (n > 0) {
        cout << 'a';
        S(k - 1, n - 1);
        cout << 'd';
    } else {
        cout << 'b';
        S(k - 1, n);
        cout << 'c';
    }
}
int main()
{
    int k;
    cin >> k;
    for (int n = k / 2 - 1; n > 0; --n) {
        S(k / 2, n);
        cout << endl;
    }
}