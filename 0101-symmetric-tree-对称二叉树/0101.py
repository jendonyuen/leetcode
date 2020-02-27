# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def check(self, left, right):
        if not left or not right:
            return not left and not right
        if left.val != right.val:
            return False
        return self.check(left.left, right.right) and self.check(left.right, right.left)

    def isSymmetric(self, root: TreeNode) -> bool:
        if not root :
            return True
        return self.check(root.left, root.right)