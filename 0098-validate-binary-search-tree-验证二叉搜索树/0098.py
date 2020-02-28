# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = [(root, float('-inf'), float('inf'))]
        while stack:
            root, low, up = stack.pop()
            if not root :
                continue
            if root.val <= low or root.val >= up:
                return False
            stack.append((root.left, low, root.val))
            stack.append((root.right, root.val, up))
        return True