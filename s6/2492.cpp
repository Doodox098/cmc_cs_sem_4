#include <map>
#include <vector>

class Solution {
private:
    int min = 0;
    std::map<int, std::vector<std::pair<int, int>>> graph;
public:
    int find_min(int idx) {

    }
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        for (auto &road : roads) {
            auto it = graph.find(road[0]);
            if (it != graph.end()) {
                it->second.emplace_back(road[1], road[2]);
            } else {
                graph.insert(std::vector<std::pair<int, int>>(road[1], road[2]));
            }
        }
        return find_min(1);
    }
};