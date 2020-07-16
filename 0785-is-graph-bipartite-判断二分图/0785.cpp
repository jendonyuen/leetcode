// 相邻节点染不同颜色
class Solution {
    unordered_set<int> visited;
    vector<int> colors;
    bool res = true;
    void dfs(vector<vector<int>>& graph, int i, int color) {
        if (visited.count(i)) {
            if (colors[i] != color) res = false;
            return;
        }
        visited.insert(i);
        if (colors[i] == 0) {
            colors[i] = color;
            for (auto &j: graph[i]) {
                dfs(graph, j, color == 1 ? 2 : 1);
            } 
        } else if (colors[i] == color) {
            res = false;
        }
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        colors.resize(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (!visited.count(i)) {
                dfs(graph, i, colors[i] == 1 ? 2 : 1);
            }
        }
        
        return res;
    }
};