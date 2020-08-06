// 字典树

class TrieNode {
public:
    bool end = false;
    TrieNode* next[26];
    int index = INT_MIN;
    // 正序插入
    void insert(string& s, int index) {
        TrieNode* node = this;
        for (auto it = s.begin(); it != s.end(); ++it) {
            int i = *it - 'a';
            if (!node->next[i]) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->end = true;
        node->index = index;
    }
};


class RTrieNode {
public:
    bool rend = false;
    RTrieNode* next[26];
    int index = INT_MIN;
    // 倒序插入
    void rinsert(string& s, int index) {
        RTrieNode* node = this;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            int i = *it - 'a';
            if (!node->next[i]) {
                node->next[i] = new RTrieNode();
            }
            node = node->next[i];
        }
        node->rend = true;
        node->index = index;
    }
};

class Solution {
    bool check(string& s, int i) {
        int p = s.size() - 1;
        while(i < p) {
            if (s[i++] != s[p--]) return false;
        }
        return true;
    }
    bool rcheck(string &s, int i) {
        int p = 0;
        while(p < i) {
            if (s[p++] != s[i--]) return false;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<vector<int>> st;
        vector<vector<int>> res;
        TrieNode* trie = new TrieNode();
        RTrieNode* rtrie = new RTrieNode();

        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i], i);
            rtrie->rinsert(words[i], i);
        }

        for (int j = 0; j < words.size(); ++j) {
            auto node = rtrie;
            string& word = words[j];
            if (node->rend && node->index != j) {
                if (check(word, 0)) {    // 检查该字符串剩余部分能否形成回文
                    st.insert({j, node->index});
                } 
            }  
            
            for (int i = 0; i < word.size(); ++i) {
                if (node->next[word[i]-'a']) {
                    node = node->next[word[i]-'a'];
                } else break;

                if (node->rend && node->index != j) {
                    if (check(word, i + 1)) {    // 检查该字符串剩余部分能否形成回文
                        st.insert({j, node->index});
                    } 
                }  
            }
            {   // 反向检查
                auto node = trie;
                string& word = words[j];
                if (node->end && node->index != j) {
                    if (rcheck(word, word.size() - 1)) {    // 反向检查该字符串剩余部分能否形成回文
                        st.insert({node->index, j});
                    } 
                }  
                
                for (int i = word.size() - 1; i >= 0; --i) {
                    if (node->next[word[i]-'a']) {
                        node = node->next[word[i]-'a'];
                    } else break;

                    if (node->end && node->index != j) {
                        if (rcheck(word, i-1)) {    // 反向检查该字符串剩余部分能否形成回文
                            st.insert({node->index, j});
                        } 
                    }  
                }
            }
        }

        for (auto &a: st) {
            res.emplace_back(a);
        }
        return res;
    }
};