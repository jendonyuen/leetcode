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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head) return head;
        ListNode* node = head;
        while(node->next) {
            if (node->next->val == val) {
                ListNode* t = node->next;
                node->next = node->next->next;
                delete t;
            } else node = node->next;
        }
        return head;
    }
};