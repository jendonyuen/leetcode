class Solution {
private:
    stack<int> res;
    
    // 课程n的状态:  0:未搜索, 1:搜索中, 2:已完成
    vector<int> status;

    // 存储有向图
    /*
    课程0   |   先学[课程1], [课程2]
    课程1   |   先学[课程2]
    课程2   |   先学[课程3]
    课程3   |   无
    */
    vector<vector<int>> graph;

    // 深度优先搜索
    // return true: 无效
    bool dfs(int u) {
        status[u] = 1;
        for (const auto &a: graph[u]) {
            // 如果节点未搜索, 搜索该节点
            if (status[a] == 0) {
                if (dfs(a)) return true;
            } else if (status[a] == 1){
                // 如果节点处于搜索中, 那么存在环, 无法完成环内课程学习
                return true;
            } 
        }
        // 该节点搜索完成
        status[u] = 2;
        // 放入结果result中
        res.push(u);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        status.resize(numCourses);
        graph.resize(numCourses);
        for (const auto &prq: prerequisites) {
            // cout << prq[1] << "," << prq[0] << endl;
            graph[prq[1]].push_back(prq[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!status[i]) {
                if (dfs(i)) return {};
            }
        }
        vector<int> ans;
        while(!res.empty()) {
            ans.push_back(res.top());
            res.pop();
        }
        return ans;
    }
};