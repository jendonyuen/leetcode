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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        p1 = p1->next;
        p2 = p2->next->next;
        while(p1 && p2 && p2->next) {
            if (p1 == p2) {
                p2 = head;
                while(true) {
                    if (p1 == p2) return p1;
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return NULL;
    }
};