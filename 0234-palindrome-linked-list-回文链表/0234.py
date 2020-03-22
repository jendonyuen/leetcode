# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # O(n)时间复杂度, O(1)空间复杂度, 最后将链表结构恢复
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next: return True
        slow = head
        fast = head
        last = head
        nextNode = slow.next
        while slow:
            if fast.next and fast.next.next:
                fast = fast.next.next
                slow = nextNode
                nextNode = slow.next
                slow.next = last
                last = slow
            else:
                if not fast.next:   # 奇
                    fast = last.next
                    slow = nextNode
                    break
                else:               # 偶
                    fast = last
                    slow = nextNode
                    break

        # fast往前遍历, slow继续向后遍历
        # 恢复链表结构
        nextNode = fast.next
        while slow:
            if slow.val != fast.val: return False
            slow = slow.next
            fast = nextNode
            nextNode = fast.next
            fast.next = last
            last = fast

        return True
