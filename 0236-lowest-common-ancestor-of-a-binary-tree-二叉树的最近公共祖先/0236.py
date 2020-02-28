# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack = [[root]]
        ancestorsP = []
        ancestorsQ = []
        while stack:
            nodes = stack.pop()
            if not nodes[-1]:
                continue
            if len(ancestorsP) > 0 and len(ancestorsQ) > 0:
                # 若双方的祖先节点都找到, 则终止
                break
            if nodes[-1] == p:
                ancestorsP = nodes
            if nodes[-1] == q:
                ancestorsQ = nodes
            left = nodes.copy()
            left.append(nodes[-1].left)
            right = nodes.copy()
            right.append(nodes[-1].right)
            stack.append(left)
            stack.append(right)


        # 寻找双方祖先节点的交点, 解法类似第160题相交链表
        aP = ancestorsQ + ancestorsP
        aQ = ancestorsP + ancestorsQ
        pointerP = len(aP) - 1
        pointerQ = len(aQ) - 1
        while aP[pointerP] != aQ[pointerQ]:
            pointerP -= 1
            pointerQ -= 1
        return aP[pointerP]
            

            
