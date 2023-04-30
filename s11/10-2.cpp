#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include <algorithm>

using std::vector, std::map, std::pair, std::string, std::make_pair;

struct Node
{
    char t;
    bool visited = false;
    map<char, Node*> connections{};
    Node(char t):t(t){};
    void connect(Node* other) {
        connections.try_emplace(other->t, other);
    }
};

void find_reachable(Node* node, vector<char> &reachable)
{
    if (node->visited) return;
    node->visited = true;
    for (auto &elem : node->connections) {
        reachable.push_back(elem.first);
        find_reachable(elem.second, reachable);
    }
}

int main() {
    string rule;
    vector<string> rules;
    map<char, Node*> nodes;
    while (std::getline(std::cin, rule)) {
        rules.push_back(rule);
        if (!nodes.contains(rule[0])) {
            auto a = new Node(rule[0]);
            nodes.emplace(rule[0], a);
        }
        Node & cur = *nodes[rule[0]];
        for (long unsigned int i = 2; i < rule.length(); ++i) {
            if (isupper(rule[i])) {
                if (!nodes.contains(rule[i])) {
                    auto a = new Node(rule[i]);
                    nodes.emplace(rule[i], a);
                }
                cur.connect(nodes[rule[i]]);
            }
        }
    }
    vector<char> reachable;
    reachable.push_back('S');
    find_reachable(nodes['S'], reachable);
    for (auto &elem : rules) {
        if (std::find(reachable.begin(), reachable.end(), elem[0]) != reachable.end()) {
            std::cout << elem << std::endl;
        }
    }
}