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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int i = 0;
        while(p2->next && i < k) {
            p2 = p2->next;
            i++;
        }
        if (i != k) {
            k = k % (i+1);
            p2 = head;
            i = 0;
            while(p2->next && i < k) {
                p2 = p2->next;
                i++;
            }
        }
        if (p1 == p2) return head;
        while(p2->next) {
            p2 = p2->next;
            p1 = p1->next;
        }
        ListNode* ans = p1->next;
        p2->next = head;
        p1->next = NULL;
        return ans;
    }
};