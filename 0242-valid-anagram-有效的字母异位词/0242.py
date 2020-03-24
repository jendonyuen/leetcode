class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        table = {}
        for c in s:
            if c in table:
                table[c] += 1
            else:
                table[c] = 1
        for c in t:
            if c in table:
                table[c] -= 1
                if table[c] < 0:
                    return False
            else:
                return False
        for k, v in table.items():
            if v > 0:
                return False
        return True