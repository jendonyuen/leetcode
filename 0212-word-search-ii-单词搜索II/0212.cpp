// 字典树
class TrieNode {
public:
    bool end = false;
    bool rend = false;
    TrieNode* next[26];
    // 正序插入
    void insert(string& s) {
        TrieNode* node = this;
        for (auto &c: s) {
            int i = c - 'a';
            if (!node->next[i]) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->end = true;
    }
    // 倒序插入
    void rinsert(string& s) {
        TrieNode* node = this;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            int i = *it - 'a';
            if (!node->next[i]) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->rend = true;
    }
};


class Solution {
    TrieNode* dict = new TrieNode();
    vector<vector<int>> searched;
    unordered_set<string> res;
    string cur;
    void backTrack(vector<vector<char>>& board, TrieNode* node, int y, int x) {
        if (searched[y][x]) return;
        int i = board[y][x] - 'a';
        if (!node->next[i]) return;

        node = node->next[i];
        cur.push_back(board[y][x]);
        searched[y][x] = 1;
        if (node->end) res.insert(cur);

        if (y < board.size()-1) backTrack(board, node, y+1, x);
        if (x < board[0].size()-1) backTrack(board, node, y, x+1);
        if (y > 0)backTrack(board, node, y-1, x);
        if (x > 0)backTrack(board, node, y, x-1);


        cur.pop_back();
        searched[y][x] = 0;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        searched.resize(board.size(), vector<int>(board[0].size(), 0));
        for (auto &word : words) {
            dict->insert(word);
        }

        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                backTrack(board, dict, y, x);
            } 
        }

        vector<string> v;
        for (auto &word : res) {
            v.push_back(word);
        }
        return v;
    }
};