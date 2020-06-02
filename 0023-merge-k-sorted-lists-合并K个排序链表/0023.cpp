/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    priority_queue<int, vector<int>, greater<>> pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool b = true;
        while (b) {
            b = false; 
            for (auto &node: lists) {
                if (node) {
                    b = true;
                    pq.push(node->val);
                    node = node->next;
                } 
            } 
        }
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        while(!pq.empty()) {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        return ans->next;
    }
};