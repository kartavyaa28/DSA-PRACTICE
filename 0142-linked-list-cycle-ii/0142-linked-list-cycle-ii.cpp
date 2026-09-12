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
        ListNode* slow = head;
        ListNode* fast = head;

        //detect cycle
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }

        // no cycle
        if(fast == nullptr || fast->next == nullptr) // empty or one node
        return nullptr;

        slow = head;// we can also use fast here
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};