class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) < k: 
            return 0
        t = min(set(s), key=s.count)
        if s.count(t) >= k:
            return len(s)
        return max(self.longestSubstring(a, k) for a in s.split(t))

# 分治
# ref: https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/hua-dong-chuang-kou-fen-zhi-fa-by-powcai/