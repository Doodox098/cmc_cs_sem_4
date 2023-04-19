#include <stack>
#include <iostream>

using std::cout, std::endl, std::stack;

int main()
{
    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1.top() << endl;
    s1.pop();
}