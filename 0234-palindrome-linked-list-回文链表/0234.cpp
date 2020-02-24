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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        stack<ListNode> stk;
        stk.push(*head);
        auto slow = head;
        auto fast = head;
        // 快慢指针遍历，入栈，找到中间点
        while(fast->next && fast->next->next) {
            slow = slow->next;
            stk.push(*slow);
            fast = fast->next->next;
        }

        // 根据size奇偶性处理中间点
        if (!fast->next) {
            // 数据元素个数为奇数
            stk.pop();
        }

        // 对比前半部分和后半部分，出栈
        while(!stk.empty()) {
            slow = slow->next;
            // 注意此处对比的是val
            if (stk.top().val != slow->val) return false;
            stk.pop();
        }
        return true;

    }
};