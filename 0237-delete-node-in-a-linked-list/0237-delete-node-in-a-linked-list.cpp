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
    void deleteNode(ListNode* node) {
        // copy the next node val into given node val
        node->val = node->next->val;

        ListNode* temp = node->next; // using to remove completely next node , prevention from memory leak

        //now point current node to its next of next node , it will reduce its next node

        node->next = node->next->next;

        delete temp;

        
        
    }
};