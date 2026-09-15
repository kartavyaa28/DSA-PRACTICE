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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        vector<int>odd;
        vector<int>even;

        ListNode* temp = head;
        int idx = 1;
        while(temp != nullptr)
        {
            if(idx % 2 == 0) even.push_back(temp->val);
            else odd.push_back(temp->val);
            idx++;
            temp=temp->next;

        }
        for(int x : even)odd.push_back(x);
        temp = head;
        int j = 0;
        while(temp != nullptr && j < odd.size())
        {
            temp->val = odd[j++];
            temp = temp->next;
        }
        return head;
        
    }
};