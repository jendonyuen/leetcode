class Solution:
    def isHappy(self, n: int) -> bool:
        t = n
        resultDict = {}
        while True:
            if t == 1: return True
            if t in resultDict:
                return False
            else: resultDict[t] = False
            r = 0
            while t > 0:
                m = (t % 10) * (t % 10)
                r += m
                t = t // 10
            t = r

        return False
