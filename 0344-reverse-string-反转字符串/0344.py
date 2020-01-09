class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in range(len(s) // 2):
            k = len(s) - i - 1
            #s[i] = ord(s[i]) + ord(s[k])
            #s[k] = s[i] - ord(s[k])
            #s[i] = chr(s[i] - s[k])
            #s[k] = chr(s[k])

            t = s[i]
            s[i] = s[k]
            s[k] = t