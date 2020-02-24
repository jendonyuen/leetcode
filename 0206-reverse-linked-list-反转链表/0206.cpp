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
        ListNode* p1 = NULL;
        ListNode* p2 = head;

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