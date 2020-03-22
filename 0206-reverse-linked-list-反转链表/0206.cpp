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
    // 迭代
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

    /*
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    */
};