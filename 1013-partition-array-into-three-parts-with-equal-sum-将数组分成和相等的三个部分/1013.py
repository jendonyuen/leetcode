class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        target = sum(A)
        if target % 3 != 0:
            return False
        target /= 3

        p1, p2 = 0, 1
        t1, t2 = 0, 0

        size = len(A)
        for p1 in range(size):
            t1 += A[p1]
            if t1 == target:
                break
        if t1 != target:
            return False

        for p2 in range(p1+1, size):
            t2 += A[p2]
            if t2 == target:
                break
        if t2 != target:
            return False
        
        if p2 == size - 1:
            return False

        if sum(A[p2+1:]) == target:
            return True
        
        return False