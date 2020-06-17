/*
建立一个矩阵, 存放第2^n个祖先节点;
矩阵第一行是当前节点的第k=1个祖先, 即传入的数组parent;
由于n <= 50000 < 2 ^ 16 = 65536, 故需要共16行矩阵, 最后一行是当前节点的第k=32768个祖先;
[-1,  0,  1,  2,  3,  4,  5,  6,  7,  8] 2^0 = 1
[-1, -1,  0,  1,  2,  3,  4,  5,  6,  7] 2^1 = 2
[-1, -1, -1, -1,  0,  1,  2,  3,  4,  5] 2^2 = 4
[-1, -1, -1, -1, -1, -1, -1, -1, -1,  0] 2^3 = 8
[.                                     ] 2^4 = 16 
[.                                     ] 2^n = ... 
[-1, -1, -1, -1, -1, -1, -1, -1, -1, -1] 2^15 = 32768

查找: 比如查找node的第18个祖先, 即[当前node的第16个祖先]的第2个祖先: 
18 = 2^4 + 2^1 = 16 + 2

node = parent[node][16];
node = parent[node][2];

题解链接: https://leetcode-cn.com/problems/kth-ancestor-of-a-tree-node/solution/jian-li-ju-zhen-an-bei-zeng-chu-cun-zu-xian-jie-di/

*/


class TreeAncestor {
    vector<vector<int>> parents;
    vector<int> vi;
public:
    TreeAncestor(int n, vector<int>& parent) {
        // 做一个索引列表[1, 2, 4, 8, ..., 32768]
        int t = 1;
        for (int i = 0; i < 16; ++i) {
            vi.push_back(t);
            t *= 2;
        }

        // 建立一个矩阵
        parents.resize(n, vector<int>(16));
        for (int i = 0; i < n; ++i) {
            parents[i][0] = parent[i];
        }
        for (int j = 1; j < 16; ++j) {
            for (int i = 0; i < n; ++i) {
                if (parents[i][j-1] == -1) {
                    parents[i][j] = -1;
                } else {
                    parents[i][j] = parents[parents[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 15; i >= 0; --i) {
            if (node == -1 || k == 0) break;
            if (k >= vi[i]) {
                node = parents[node][i];
                k -= vi[i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

