class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        totalGas = 0    # 从0开始遍历的总汽油(可为负数)
        beg = -1        # 出发索引beg
        curGas = 0      # 出发后拥有的汽油
        for i in range(len(gas)):
            t = gas[i] - cost[i]
            totalGas += t

            if beg == -1:               # 如果还没找到可出发的加油站
                if gas[i] >= cost[i]:   # 如果加油>花费,则可从当前加油站出发
                    beg = i
                    curGas += t
            else:
                curGas += t
            
            if curGas < 0:              # 如果出发后，油用完了，重置，等待寻找下一个可出发加油站
                beg = -1
                curGas = 0

        if totalGas >= 0:               # 计算最终加的油是否够用
            return beg

        return -1