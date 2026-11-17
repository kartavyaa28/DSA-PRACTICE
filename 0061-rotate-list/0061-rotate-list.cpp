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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        int len = 0;
        ListNode* lastNode = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {
            lastNode = temp;
            temp = temp->next;
            len++;
        }

        k %= len;
        if (k == 0)
            return head;

        lastNode->next = head; // make circular

        int mov = len - k;
        temp = head;

        while (--mov) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr; // break circle

        return newHead;
    }
};