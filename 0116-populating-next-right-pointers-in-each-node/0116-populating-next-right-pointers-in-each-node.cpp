/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)return nullptr;
        Node* LeftMost = root; //it will be used to change level
        while(LeftMost->left != nullptr)
        {
            Node* curr = LeftMost;
            while(curr != nullptr)
            {
                curr->left->next = curr->right; //connecting childs of root
                if(curr->next != nullptr)
                {
                    curr->right->next = curr->next->left; //connecting 5->6 in ex
                }
                curr = curr->next;
            }

            LeftMost = LeftMost->left;
        }
        return root;
    }   
};