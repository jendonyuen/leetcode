// ref: https://leetcode-cn.com/problems/re-space-lcci/solution/hui-fu-kong-ge-by-leetcode-solution/
// 字典树+动态规划
// dp[i+1]表示从s[i]往前有多少个未识别的字符数

class TrieNode {
public:
    bool isEnd = false;
    TrieNode* next[26];
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> dp(sentence.size()+1, INT_MAX);
        dp[0] = 0;
        
        // 构造字典树, 倒序插入单词
        TrieNode* root = new TrieNode();
        for (auto &word: dictionary) {
            TrieNode* node = root;
            for (int i = word.size() - 1; i >= 0; --i) {
                int j = word[i]-'a';
                if (!node->next[j]) {
                    node->next[j] = new TrieNode();
                }
                node = node->next[j];
            }
            node->isEnd = true;
        }

        // 搜索时倒序向前查询
        for (int i = 0; i < sentence.size(); ++i) {
            dp[i+1] = dp[i] + 1;
            TrieNode* node = root;
            int k = 0;
            int j = sentence[i] - 'a';
            while(node->next[j]) {
                k++;
                node = node->next[j];
                if (node->isEnd) {
                    dp[i+1] = min(dp[i-k+1], dp[i+1]);
                } 
                if (i - k < 0) break;
                j = sentence[i-k] - 'a';
            }
            // cout << dp[i+1] << ", ";
        } // cout << endl;

        return dp.back();
    }
};