# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        rtn = ListNode(0)
        l = rtn
        p1 = l1
        p2 = l2
        while p1 and p2:
            if p1.val < p2.val:
                l.next = p1
                p1 = p1.next
            else:
                l.next = p2
                p2 = p2.next
            l = l.next
        
        while p1:
            l.next = p1
            p1 = p1.next
            l = l.next

        while p2:
            l.next = p2
            p2 = p2.next
            l = l.next

        return rtn.next