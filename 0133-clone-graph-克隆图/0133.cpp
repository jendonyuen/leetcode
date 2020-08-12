/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);    // 将深拷贝存储在hash_map中

        queue<Node*> que;
        que.push(node);

        // 通过queue进行BFS
        while(!que.empty()) {
            for (int i = que.size(); i > 0; --i) {
                auto cur = que.front();
                que.pop();
                for (auto& nb: cur->neighbors) {
                    if (!visited.count(nb)) {   // 未访问过的建立深拷贝, 并入队
                        visited[nb] = new Node(nb->val);
                        que.push(nb);   
                    }  
                    visited[cur]->neighbors.emplace_back(visited[nb]);  // 更新深拷贝的neighbotrs
                }
            }
        }

        return visited[node];
    }
};

// DFS
class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return nullptr;
        visited[node] = new Node(node->val);

        for (auto& nb: node->neighbors) {
            if (!visited.count(nb)) {
                cloneGraph(nb); // dfs
            } 
            visited[node]->neighbors.emplace_back(visited[nb]);
        }

        return visited[node];
    }
};