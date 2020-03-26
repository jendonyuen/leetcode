# 牛顿迭代法
# 逼近

class Solution:
    def mySqrt(self, x: int) -> int:
        last = 0
        ans = 1

        while ans != last:
            last = ans
            ans = (ans + x / ans) / 2

        return ans