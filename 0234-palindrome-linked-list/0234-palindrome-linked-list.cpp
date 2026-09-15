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
    ListNode* reverseLL(ListNode* head) // we are using iter rev because its more s/c->o(1)
    {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {

        //handling edge case
        if(head == nullptr || head->next == nullptr)
        return true;

    
        ListNode* mid = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode* newNode = reverseLL(mid->next);
        
        ListNode* first = head; //original first half
        ListNode* second = newNode; // reversed second half

        while(second != nullptr)
        {
            if(first->val != second->val)
            {
                reverseLL(newNode); // reversing back to its original link
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseLL(newNode);
        return true;

        
    }
};