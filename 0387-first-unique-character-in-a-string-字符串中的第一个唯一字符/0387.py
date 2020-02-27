class Solution:
    def firstUniqChar(self, s: str) -> int:
        table = {}
        i = 0
        for c in s:
            if c not in table:
                table[c] = i
            else: 
                table[c] = -1
            i += 1

        for key, value in table.items():
            if value >= 0:
                return value

        return -1