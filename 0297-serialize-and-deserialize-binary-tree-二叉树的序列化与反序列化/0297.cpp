
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        vector<TreeNode*> v;
        if (root) v.push_back(root);
        while(!v.empty()) {
            vector<TreeNode*> vt;
            for (auto &node: v) {
                if (node) {
                    res += to_string(node->val);
                    vt.emplace_back(node->left);
                    vt.emplace_back(node->right);
                } else {
                    res += "null";
                }
                res.push_back(',');
            }
            v = vt;
        }

        while(res.size() > 5 && res.substr(res.size() -5, 5) == "null,") {
            res = res.substr(0, res.size() - 5);
        }
        if (res.back() == ',') {
            res.pop_back();
        }
        res.push_back(']');

        return res;
    }

    inline string findNode(string &data, int p) {
        if (p >= data.size()) return "";
        auto pos = data.find(',', p);
        if (pos == data.npos) {
            if (data[p] < '0' && data[p] > '9') {
                // data[p:] = "]"
                return "";
            } else {    
                // data[p:] = "52]"
                return data.substr(p, data.size() - p);
            }
        }
        // data[p:] = "48,49,50,51,52]"
        return data.substr(p, pos - p);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() <= 2 || data[0] != '[') return NULL;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        int p = 1;
        bool b = true;
        string s = findNode(data, p);
        TreeNode* root;
        if (s.size() != 0 && s != "null") {
            root = new TreeNode(stoi(s));
        } 
        q1.push(root);
        p += s.size() + 1;
        s = findNode(data, p);
        while(s.size() != 0) {
            // find parent
            TreeNode* parent = NULL;
            while(!parent) {
                if (q1.size() > 0) {
                    if (q1.front()) parent = q1.front();
                    else q1.pop();
                } else {
                    q1 = q2;
                    q2 = {};
                }
            }

            // find curr
            TreeNode* newNode = NULL;
            if (s != "null") newNode = new TreeNode(stoi(s));
            if (b) {
                if (newNode) parent->left = newNode;
                b = !b;
            } else {
                if (newNode) parent->right = newNode;
                q1.pop();
                b = !b;
            }
            q2.push(newNode);
            p += s.size() + 1;
            s = findNode(data, p);
        }        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));