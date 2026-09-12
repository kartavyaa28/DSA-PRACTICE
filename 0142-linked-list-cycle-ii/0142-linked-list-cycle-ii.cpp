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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp; // we can use hashset here for more mem eff because we only care about existence not mapping
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(mp.find(temp) != mp.end())return temp;
            mp[temp] = 1;
            temp = temp->next;
        }
        

        return nullptr;

        
    }
};