# 蓄水池抽样算法
# 链表特点：数据量十分大，无法将所有数据加载到内存中，且长度未知，如何在复杂的O(1)即只遍历一遍的情况下随机取样？
# 1.待取样个数k(本题中k==1)
# 2.将前k个元素放入池中
# 3.从k+1个元素开始向后遍历, 索引i=k+n...
# 4.当前元素有k/i的概率替换到池中
# 5.池中任一元素被替换掉的概率为1/k
# 6.最后返回池中元素

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import random

class Solution:

    def __init__(self, head: ListNode):
        self.head = head        
        
    def getRandom(self) -> int:
        rtn = self.head.val
        count = 1
        node = self.head.next
        while node:
            r = random.randint(0, count)   # generate [0, count]
            if r == 0:                     # P(r==0) = 1 / count
                rtn = node.val
            node = node.next
            count += 1
        return rtn

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()