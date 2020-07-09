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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* prev = head;
        ListNode* node = head->next;
        while(node) {
            if (node->val == prev->val) {
                prev->next = node->next;
                delete node;
                node = prev->next;
            } else {
                prev = node;
                node = node->next;
            }
        }
        return head;
    }
};