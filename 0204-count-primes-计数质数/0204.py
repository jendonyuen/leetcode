class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2: return 0
        arr = [1 for _ in range(n+1)]
        count = 0
        for i in range(2, n):
            if arr[i] == 1:
                count += 1
            if i <= int(math.sqrt(n)):
                for j in range(i, n // i + 1):
                    arr[i*j] = 0
        
        return count


