#include <string>
#include <iostream>
#include <stack>
#include <sstream>

int main()
{
    char cur;
    std::stack<std::string> stack;
    while (std::cin >> cur) {
        if (cur == ' ' || cur == '\n') continue;
        if (isalpha(cur)) {
            std::ostringstream out;
            out << cur;
            stack.push(out.str());
        } else {
            std::ostringstream out;
            out.clear();
            auto op2 = stack.top();
            stack.pop();
            auto op1 = stack.top();
            stack.pop();
            out << '(' << op1 << cur << op2 << ')';
            stack.push(out.str());
        }
    }
    std::cout << stack.top();
}