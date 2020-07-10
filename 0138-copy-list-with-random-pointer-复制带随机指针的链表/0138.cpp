/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        if (m.count(head)) {
            return m[head];
        } 

        Node* res = new Node(head->val);
        m[head] = res;
        res->next = copyRandomList(head->next);
        res->random = copyRandomList(head->random);
        return res;
    }
};