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
        int size = 0;
        while(temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        temp = head;
        int i = 1;
        while(temp != nullptr && i <= size)
        {
            if(i % 2 == 0){
            even.push_back(temp->val);
            i++;}
            else
            {
            odd.push_back(temp->val);
            i++;}
            temp=temp->next;

        }
        for(int i = 0 ; i < even.size() ; i++)
        {
            odd.push_back(even[i]);
        }
        temp = head;
        int j = 0;
        while(temp != nullptr && j < odd.size())
        {
            temp->val = odd[j];
            temp=temp->next;
            j++;
        }
        return head;
        
    }
};