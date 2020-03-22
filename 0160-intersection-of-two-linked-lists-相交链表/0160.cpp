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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        bool b1 = true;
        bool b2 = true;
        while (true) {
            if (!p1) {
                if (b1) {
                    p1 = headB;
                    b1 = false;
                }
                else return NULL;
            }
            if (!p2) {
                if (b2) {
                    p2 = headA;
                    b2 = false;
                }
                else return NULL;
            }
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};