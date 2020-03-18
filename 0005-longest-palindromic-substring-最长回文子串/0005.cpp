class Solution {
public:
    // 中心扩展法
    string longestPalindrome(string s) {
        if (s.size() < 2) return s; 
        int beg = 0;
        int end = 0;
        // 设i为中心
        for (int i = 0; i != s.size(); ++i) {
            bool odd = true;
            bool even = true;
            // 向两侧搜寻, 分别搜寻奇回文和偶回文
            for (int left = i-1; left >= 0; --left) {
                // 如果奇偶回文均中断, 则中止搜索
                if (!odd && !even) break;
                int right = i+i-left;
                // 偶回文搜寻到右侧最远端
                if (right >= s.size() + 1) break;
                if (s[left] == s[right-1] && even) {
                    if (right-1 - left > end - beg) {
                        beg = left;
                        end = right-1;
                    }
                } else even = false;
                // 寻找以i为中心的最大奇回文子串
                // 奇回文搜寻到右侧最远端, 由于偶回文还能搜寻一次，所以continue
                if (right >= s.size()) continue;
                if (s[left] == s[right] && odd) {
                    if (right - left > end - beg) {
                        beg = left;
                        end = right;
                    }
                } else odd = false;
            }
        }
        return s.substr(beg, end-beg + 1);
    }
};