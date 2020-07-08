// 分治
// ref: https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/hua-dong-chuang-kou-fen-zhi-fa-by-powcai/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        // 查找字符串中出现次数最少的字母
        unordered_map<char, int> um;
        for (auto &a : s) {
            um[a]++;
        }
        int c, n = INT_MAX;
        for (auto &p : um) {
            if (p.second < n) {
                n = p.second;
                c = p.first;
            }
        }

        // 如果出现次数最少的字母个数大于k, 则当前子串都有效
        if (n >= k) return s.size();

        // 按出现次数个数最少的字母进行分割, 搜索(分而治之)
        string splited;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                res = max(longestSubstring(splited, k), res);
                splited = "";
            } else {
                splited.push_back(s[i]);
            }
        }
        res = max(longestSubstring(splited, k), res);
        return res;
    }
};