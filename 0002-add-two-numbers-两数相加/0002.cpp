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
        int sum = 0;
        bool isCarry = false;
        ListNode *lrt = NULL, *p;
        while(l1 != NULL || l2 != NULL || isCarry!=0){
            sum = 0;
            if(l1 != NULL){
                sum += l1->val; 
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val; 
                l2 = l2->next; 
            }
            if(isCarry == true)++sum;
            isCarry = false;
            if(sum>=10){
                sum -= 10;
                isCarry = true;
            }
            ListNode *lTemp = new ListNode(sum);
            if(lrt != NULL){
                p->next = lTemp;
                p = p->next;
            }else{
                lrt = lTemp;
                p = lTemp;
            }
        }
        return lrt;
    }
};