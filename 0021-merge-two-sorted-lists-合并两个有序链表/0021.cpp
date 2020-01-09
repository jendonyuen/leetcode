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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        bool isBreak = false;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while(l1||l2){
            if(l1 && l2){
                if(l1->val<=l2->val){
                    temp->next = new ListNode(l1->val);
                    temp=temp->next;
                    l1=l1->next;
                }else{
                    temp->next = new ListNode(l2->val);
                    temp=temp->next;
                    l2=l2->next;
                }
            }else{
                if(l1){
                    temp->next = new ListNode(l1->val);
                    temp=temp->next;
                    l1=l1->next;
                }
                if(l2){
                    temp->next = new ListNode(l2->val);
                    temp=temp->next;
                    l2=l2->next;
                }
            }
        }return result->next;
    }
};