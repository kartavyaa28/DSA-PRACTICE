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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //ListNode*dummy = new ListNode{0,nullptr};//heap allocate have to delete this node later
        ListNode dummy(0);//stack allocated , lifetime is only for this function
        ListNode* dd = &dummy;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                dd->next = list1;
                dd = dd->next;
                list1 = list1->next;
            }
            else
            {
                dd->next = list2;
                dd = dd->next;
                list2 = list2->next;
            }
        }

        // attaching remaining node
        dd->next = (list1 ? list1 : list2);

        return dummy.next; // it is a stack object so we have to use . instead of ->
        
    }
};