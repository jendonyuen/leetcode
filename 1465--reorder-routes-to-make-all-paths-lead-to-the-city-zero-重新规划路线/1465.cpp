// 第 191 场周赛

class Solution {
    int ans = 0;
    unordered_set<int> searched;
    bool search(vector<unordered_set<int>> &graph, int i) {
        if (searched.find(i) != searched.end()) return true;
        bool isConn = false;
        if (graph[i].find(0) == graph[i].end()) {
            // 该节点不能直接到0, 查找子节点能否到0
            for (auto &a: graph[i]) {
                if (search(graph, a)) {
                    isConn = true;
                }
            }
        } else {isConn = true;}
        if (!isConn) {
            // cout << i << endl;
            ans++;
        }
        graph[i].insert(0);
        searched.insert(i);
        return isConn;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> us;
        vector<unordered_set<int>> graph(n, us);
        for (auto &con: connections) {
            graph[con[0]].insert(con[1]);
        }
        
        for (int i = 1; i < graph.size(); ++i) {
            // cout << "search:" << i << endl;
            search(graph, i);
        }
        
        return ans;
    }
};