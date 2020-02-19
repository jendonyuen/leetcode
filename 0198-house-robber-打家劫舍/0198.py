class Solution:
    # 动态规划
    # 当前i金额最大值=(i-1金额最大值)or(i-2金额最大值+i金额)
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        moneyList = [nums[0]]
        if nums[1] > nums[0]:
            moneyList.append(nums[1])
        else:
            moneyList.append(nums[0])
        for i in range(2, len(nums)):
            robMoney = nums[i] + moneyList[i-2]
            if robMoney > moneyList[i-1]:
                moneyList.append(robMoney)
            else:
                moneyList.append(moneyList[i-1])
        print(moneyList)
        return moneyList[-1]