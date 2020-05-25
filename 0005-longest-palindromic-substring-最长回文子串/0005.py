class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2: return s
        beg = 0
        end = 0
        for i in range(len(s)):
            odd = True
            even = True
            for left in range(i, -1, -1):
                if not odd and not even: break
                right = i + i - left
                if right >= len(s) + 1: break
                # 搜索偶回文至最远端
                if s[left] == s[right-1] and even:
                    if right-1-left > end - beg:
                        beg = left
                        end = right-1
                else: even = False

                if right >= len(s): continue
                if s[left] == s[right] and odd:
                    if right - left > end - beg:
                        beg = left
                        end = right
                else: odd = False
        return s[beg:end+1]