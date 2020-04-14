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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        auto p1 = l1;
        auto p2 = l2;
        while(p1) {
            st1.push(p1->val);
            p1 = p1->next;
        }
        while(p2) {
            st2.push(p2->val);
            p2 = p2->next;
        }
        
        ListNode *ans = NULL;
        bool carry = false;
        while(!st1.empty() && !st2.empty()) {
            int t = st1.top() + st2.top();
            st1.pop();
            st2.pop();
            if (carry) t++;
            if (t >= 10) {
                carry = true;
                t -= 10;
            } else {
                carry = false;
            }
            auto node = new ListNode(t);
            node->next = ans;
            ans = node;
        }

        while(!st1.empty()) {
            auto t = st1.top();
            st1.pop();
            if (carry) t++;
            if (t >= 10) {
                carry = true;
                t -= 10;
            } else {
                carry = false;
            }
            auto node = new ListNode(t);
            node->next = ans;
            ans = node;
        }

        while(!st2.empty()) {
            auto t = st2.top();
            st2.pop();
            if (carry) t++;
            if (t >= 10) {
                carry = true;
                t -= 10;
            } else {
                carry = false;
            }
            auto node = new ListNode(t);
            node->next = ans;
            ans = node;
        }

        if (carry) {
            auto node = new ListNode(1);
            node->next = ans;
            ans = node;
        }

        return ans;
    }
};