/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;

        bool b = true;
        while(true) {
            if (b) {
                if (!even->next) {
                    odd->next = evenHead;
                    return oddHead;
                }
                odd->next = even->next;
                odd = odd->next;
            } else {
                if (!odd->next) {
                    even->next = NULL;
                    odd->next = evenHead;
                    return oddHead;
                }
                even->next = odd->next;
                even = even->next;
            }
            b = !b;
        }

        return head;
    }
};