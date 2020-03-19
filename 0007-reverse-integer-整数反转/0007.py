class Solution:
    def reverse(self, x: int) -> int:
        i = 0
        ret = 0
        while (x!=0):
            if (x > 0):
                i = x % 10
            else:
                i = x % -10
            x = (x-i) / 10
            ret = ret * 10 + i
            if (ret > 2147483647 or ret < -2147483648):
                return 0
        return int(ret)