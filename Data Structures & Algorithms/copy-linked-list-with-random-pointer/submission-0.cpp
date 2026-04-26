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
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* helper = head;
        while(helper) {
            mp[helper] = new Node(helper->val);
            helper = helper->next;
        }
        mp[nullptr] = nullptr;
        helper = head;
        while(helper) {
            Node* curr = mp[helper];
            curr->next = mp[helper->next];
            curr->random = mp[helper->random];
            helper = helper->next;
        }
        return mp[head];
    }
};
