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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next) return head;
        
        unordered_set<int> us;
        us.insert(head->val);
        ListNode* prev = head;
        ListNode* p = head->next;

        while(p) {
            if (us.find(p->val) != us.end()) {
                prev->next = p->next;
                delete p;
                p = prev->next;
            } else {
                us.insert(p->val);
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};