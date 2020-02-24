# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None

        B2A = False
        A2B = False
        pA = headA
        pB = headB

        while pA != pB:
            pA = pA.next
            pB = pB.next
            if not pA:
                if not A2B:
                    A2B = True
                    pA =  headB
                else:
                    return None
            if not pB:
                if not B2A:
                    B2A = True
                    pB = headA
                else:
                    return None
        
        return pA