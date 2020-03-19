class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dict = {}
        for num in nums:
            if num in dict.keys():
                return True
            else:
                dict[num] = True
        return False