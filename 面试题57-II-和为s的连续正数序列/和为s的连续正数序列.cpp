class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target < 3:
            return []

        l = []
        
        beg = 1
        end = 2
        sum = 0
        while beg * 2 + 1 <= target:
            sum = (beg + end) * (end - beg + 1) / 2
            if sum == target:
                t = []
                for i in range(beg, end + 1):
                    t.append(i)
                l.append(t)
            if sum >= target:
                beg += 1
                continue
            end += 1

        return l