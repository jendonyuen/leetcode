/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* first, ListNode* second, int i) {
        if (i <= 1) {
            return first;
        }
        ListNode *p = second->next;
        second->next = first;
        return reverse(second, p, i - 1);
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head->next || k <= 1) return head;
        ListNode* p = head;
        ListNode* ans = NULL;
        ListNode* beg = p;
        while (true) {
            int t = k;
            ListNode* last = beg;
            beg = p;
            while (p && t) {
                p = p->next;
                t--;
            }
            if (t == 0) {
                if (!ans) {
                    ans = reverse(beg, beg->next, k);
                } else {
                    last->next = reverse(beg, beg->next, k);
                }
                beg->next = p;
            } else {
                return ans;
            }
        }
        return head;
    }
};