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
public:    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* helper = head;
        while(helper) {
            len++;
            helper = helper->next;
        }
        helper = head;
        if(len==n) {
            head = head->next;
            delete helper;
            return head;
        }
        len -= n;
        int i=1;
        while(i<len) {
            helper = helper->next;
            i++;
        }
        ListNode* temp = helper->next;
        helper->next = helper->next->next;
        delete temp;
        return head;
    }
};
