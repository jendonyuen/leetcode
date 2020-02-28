# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if nums:
            mid = int(len(nums) / 2)
            rtn = TreeNode(nums[mid])
            rtn.left, rtn.right = self.sortedArrayToBST(nums[:mid]), self.sortedArrayToBST(nums[mid+1:])
            return rtn

        