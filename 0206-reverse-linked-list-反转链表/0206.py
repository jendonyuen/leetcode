# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 递归
# 为了方便理解，引用一条评论：
# 我子节点下的所有节点都已经反转好了，现在就剩我和我的子节点 没有完成最后的反转了，所以反转一下我和我的子节点。

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p