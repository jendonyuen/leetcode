struct TrieNode {
    bool end = false;
    TrieNode* next[26];
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (auto &c : word) {
            int i = c - 'a';
            if (!node->next[i]) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (auto &c : word) {
            int i = c - 'a';
            if (!node->next[i]) return false;
            node = node->next[i];
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto &c : prefix) {
            int i = c - 'a';
            if (!node->next[i]) return false;
            node = node->next[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */