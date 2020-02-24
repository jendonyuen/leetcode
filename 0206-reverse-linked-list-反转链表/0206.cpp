/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 // 双指针法

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        p1->next = NULL;

        while(p2) {
            // change value
            ListNode* temp = p2->next;
            p2->next = p1;
            // go next
            p1 = p2;
            p2 = temp;
        }

        return p1;

    }
};