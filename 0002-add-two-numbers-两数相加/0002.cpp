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
        bool carry = false;
        ListNode* rtn = new ListNode(0);
        ListNode* cur = rtn;

        while (l1 || l2) {
            int val = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }

            if (carry) val++;
            if (val >= 10) {
                val -= 10;
                carry = true;
            } else {
                carry = false;
            }

            cur->next = new ListNode(val);              // 先指向创建的新节点
            cur = cur->next;                            // 再将当前指针移到新节点
        }
        
        if (carry) cur->next = new ListNode(1);

        return rtn->next;
    }
};