class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: return 0
        beg = 0
        end = 0
        length = 1
        table = {s[0]: 0}
        while end != len(s) - 1:
            end += 1
            if s[end] in table.keys():
                beg = max(table[s[end]] + 1, beg)
            table[s[end]] = end
            length = max(end - beg + 1, length)
        
        return length