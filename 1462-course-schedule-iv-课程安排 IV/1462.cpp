// 第 27 场双周赛

class Solution {
    vector<set<int>> graph;
    void build(int cur, int target) {
        for (auto &a: graph[target]) { 
            if (graph[cur].find(a) == graph[cur].end()) {
                graph[cur].insert(a);
                build(cur, a);   
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        graph.resize(n);
        // first build
        for (auto &a: prerequisites) {
            graph[a[1]].insert(a[0]);
        }
        
        // second build
        int cur = 0;
        for (auto &a: graph) {
            for (auto &b: a) {
                build(cur, b);   
            }
            cur++;
        }
        
        // query
        vector<bool> ans;
        for (auto &a: queries) {
            // cout << a[0] << "," << a[1] << endl;
            bool res = graph[a[1]].find(a[0]) != graph[a[1]].end();
            ans.push_back(res);
        }
        return ans;
    }
};