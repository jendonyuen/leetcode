/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto res = ListNode(0); // 头部添加哨兵
        res.next = head;
        ListNode* fast = &res;
        ListNode* slow = &res;
        while(n-- > 0) {
            fast = fast->next;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del; // 清理内存
        return res.next;
    }
};