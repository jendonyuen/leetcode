// [reference]
// https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/

// 归并排序
// 时间复杂度O(nlogn)每次遍历n个元素, 需遍历logn次
// 空间复杂度O(1), 记录每轮单元长度unitLen, 在原链表上操作
// 使用双路归并(merge)与断链(cut)方法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 将链表分割, 断开第head+len-1节点, 返回第head+len节点
    ListNode* cut(ListNode* head, int len) {
        auto p = head;
        while(p && --len > 0) {
            p = p->next;
        }
        if (!p) return NULL;
        ListNode* res = p->next;
        p->next = NULL;
        return res;
    }

    // 合并链表, 返回新的头结点, 更新尾节点
    auto merge(ListNode* l1, ListNode* l2) {
        ListNode res = ListNode(0);
        ListNode* p = &res;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        // 将多出节点连接在尾部
        p->next = l1 ? l1 : l2;
        // 将P置于尾节点
        while(p->next) p = p->next;
        return tuple(res.next, p);
    }


public:
    ListNode* sortList(ListNode* head) {
        // 获取list长度
        int len = 0;
        ListNode* p = head;
        while(p) {
            len++;
            p = p->next;
        }

        ListNode* curHead = head;
        ListNode* prevTail;
        ListNode* tail;
        for (int unitLen = 1; unitLen < len; unitLen <<= 1) {
            p = curHead;
            curHead = NULL;
            while(p) {
                auto mid = cut(p, unitLen);
                auto nextNode = cut(mid, unitLen);
                auto [res, tail] = merge(p, mid);
                if (!curHead) {
                    curHead = res;
                } else {
                    prevTail->next = res;
                }
                prevTail = tail;
                p = nextNode;
            }
        }
        return curHead;
    }
};