# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return self.getDepth(root, 0)

    def getDepth(self, root: TreeNode, depth: int) -> int:
        if root:
            depth += 1
            dL = depth
            dR = depth
            if root.left:
                dL = self.getDepth(root.left, depth)
            if root.right:
                dR = self.getDepth(root.right, depth)
            if dL >= dR:
                return dL
            return dR
        return depth