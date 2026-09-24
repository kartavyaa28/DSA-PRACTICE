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
    ListNode* MergeTwoList(ListNode* l1 , ListNode* l2)
    {
        if(l1 == nullptr)return l2;
        if(l2 == nullptr)return l1;
        if(l1->val > l2->val)swap(l1,l2);
        ListNode* res = l1;
        while(l1 != nullptr && l2 != nullptr)
        {
            ListNode* temp = nullptr;
            while(l1 != nullptr && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;//for connection
            swap(l1,l2);
        }

        return res;
    }
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)//will find first middle in even len
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return MergeTwoList(leftHead , rightHead);
       
    }
};