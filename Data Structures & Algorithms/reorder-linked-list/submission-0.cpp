/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> linklist;
        ListNode* helper = head;
        int len=0;
        while(helper) {
            linklist.push_back(helper);
            helper = helper->next;
            len++;
        }
        helper = head;
        int tail = len-1;
        int round = len%2? (len/2):(len/2)-1;
        for(int i=1;i<=round;i++) {
            ListNode* temp = helper->next;
            helper->next = linklist[tail--];
            helper->next->next = temp;
            helper = temp;
        }
        linklist[tail]->next = nullptr;
    }
};
