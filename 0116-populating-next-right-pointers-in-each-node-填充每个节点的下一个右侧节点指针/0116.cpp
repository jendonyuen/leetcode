/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    vector<vector<Node*>> levelVec;     // 层序遍历
    void levelOrderTraversal(Node* node, int level) {
        if (!node) return;
        if (levelVec.size() == level) {
            levelVec.push_back({node});
        } else {
            levelVec[level].push_back(node);
        }
        levelOrderTraversal(node->left, level+1);
        levelOrderTraversal(node->right, level+1);
    }
public:
    Node* connect(Node* root) {
        levelOrderTraversal(root, 0);
        for (auto &level: levelVec) {
            for (int i = 0; i < level.size()-1; ++i) {
                level[i]->next = level[i+1];
            }
            level.back()->next = NULL;
        }
        return root;
    }
};