class Solution:
    def isValid(self, s: str) -> bool:
        t = ['default']
        for c in s:
            if c == '(':
                t.append(')')
            elif c == '{':
                t.append('}')
            elif c == '[':
                t.append(']')
            elif t[-1] == c:
                t.pop()
            else:
                return False
        if len(t) == 1:
            return True
        return False