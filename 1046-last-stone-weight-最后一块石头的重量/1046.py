class Solution:
    def push(self, i, stone):
        if len(self.twoStones) < 2:
            self.twoStones.append((i, stone))
        elif (self.twoStones[0][1] < self.twoStones[1][1]):
            if stone > self.twoStones[0][1]:
                self.twoStones[0] = (i, stone)
        else:
            if stone > self.twoStones[1][1]:
                self.twoStones[1] = (i, stone)
    def lastStoneWeight(self, stones: List[int]) -> int:
        while (len(stones) > 1):
            self.twoStones = []
            for i in range(len(stones)):
                self.push(i, stones[i])
            # knock
            val = abs(self.twoStones[0][1] - self.twoStones[1][1])
            # (先)删除索引靠后的
            frontI = 0
            backI = 1
            if self.twoStones[0][0] > self.twoStones[1][0]:
                frontI = 1
                backI = 0
            if val :
                stones[self.twoStones[frontI][0]] = val
                del stones[self.twoStones[backI][0]]
            else:
                del stones[self.twoStones[backI][0]]
                del stones[self.twoStones[frontI][0]]
        if len(stones) > 0:
            return stones[0]
        return 0