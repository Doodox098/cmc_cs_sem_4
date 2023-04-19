#include <vector>
#include <map>
#include <functional>
#include "complex_stack.h"

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack stack;
        std::map<std::string, std::function<void()>> stof{
                {"+", [&stack]() { stack = ~~stack << (+stack + +(~stack)); }},
                {"-", [&stack]() { stack = ~~stack << (+(~stack) - +stack); }},
                {"*", [&stack]() { stack = ~~stack << (+(~stack) * +stack); }},
                {"/", [&stack]() { stack = ~~stack << (+(~stack) / +stack); }},
                {"!", [&stack]() { stack = stack << +stack; }},
                {";", [&stack]() { stack = ~stack; }},
                {"~", [&stack]() { stack = ~stack << ~+stack; }},
                {"#", [&stack]() { stack = ~stack << - +stack; }},
        };
        for (auto &elem: args) {
            if (elem == "z") {
                stack = stack << z;
            } else if (stof.contains(elem)) {
                stof[elem]();
            } else {
                stack = stack << complex(elem);
            }
        }
        return +stack;
    }
}