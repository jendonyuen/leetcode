# 二分查找
# 将矩阵转化为一维序列

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        beg = 0
        end = len(matrix) * len(matrix[0])
        while beg < end:
            mid = (beg + end) // 2
            midY = mid // len(matrix[0])
            midX = mid % len(matrix[0])
            if matrix[midY][midX] == target:
                return True
            if matrix[midY][midX] > target:
                end = mid
            else:
                beg = mid + 1
        
        return False