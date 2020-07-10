// 字典树
class TrieNode {
public:
    bool end = false;
    bool rend = false;
    // string word; // 可用word替换end
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