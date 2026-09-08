#include<iostream>

using namespace std;

struct Node{
    int data;
    Node*next;
};

void insertAtHead(Node* &head , int val)
{
    Node* newNode = new Node{val , nullptr};
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head , int val)
{ 
    Node* newNode = new Node{val , nullptr};
    //handling empty condition 
    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp=temp->next;
    }

    temp->next = newNode;
}

void insertAtMid(Node* &head , int val)
{
    Node* newNode = new Node{val,nullptr};
    //edge case 1: if linked list is empty
    if(head == nullptr)
    {
        head = newNode;
        return;

    }

    //edge case 2: if linkedlist has only one node
    if(head->next == nullptr)
    {
        head->next = newNode;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr) // when we use tortoise and hare approach , when fast reach last slow will be pointing middle node of Linked list
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    

    newNode->next = slow->next;
    slow->next = newNode;
    
}

void insertAtPosition(Node* &head, int val, int k)
{
    if(k == 1)
    {
        insertAtHead(head , val);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(cnt < k-1 && temp != nullptr)
    {
        temp = temp->next;
        cnt++;

    }

    if(temp == nullptr)
    {
        cout << "Position " << k << " is out of bounds!\n";
        return;
    }
    Node* newNode = new Node{val,nullptr};
    newNode->next = temp->next;
    temp->next = newNode;

}

void deletionAtHead(Node* &head )
{
    //edge case 1: empty list
    if(head == nullptr)
    return;

    Node* temp = head;
    head = head->next;
    delete temp;

    
}

void deletionAtTail(Node* &head)
{ 
    //edge case 1: empty list
    if(head == nullptr)
    return;

    //edge case 2: if list has only one node
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    // Stop exactly at the second-to-last node
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void deletionAtKpos(Node* &head , int k) // we have to basically traverse to k-1 node and delete it next which will be the kth nood thats the main core plus we are handling edge case below
{
    if(head == nullptr)
    return;

    //this case also handle single node problem 
    if( k == 1)
    {
        Node* curr = head;
        head = head->next;
        delete curr;
        return;

    }

    Node* temp = head;
    // Traverse until temp is at the (K-1)th node
    // We decrement k each time we move forward
    while(temp != nullptr && k > 2)
    {
        temp = temp->next;
        k--;
    }

    // Edge Case: If position K doesn't exist or K-1 is the tail node
    if(temp == nullptr || temp->next == nullptr)
    {
        cout << "Position out of bounds\n";
        return;
    }

    Node* target = temp->next;
    temp->next = target->next;
    delete target;

}

void deletionAtMid(Node* head)  // use of prev ptr 
{
    //edge case 1: if list is empty
    if(head == nullptr)
    return;

    //edge case 2 : if list has only one node
    if(head->next == nullptr)
    {
        head = nullptr;
        delete head;
        return;
    }
    
    Node* prev = nullptr;
    Node* slow = head;
    Node* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* target = prev->next;
    prev->next = target->next;
    delete target;

}


void traverse(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << "->";
        temp=temp->next;
        
    }

    cout << "nullptr\n";

}

void freeList(Node* &head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        Node* nextNode = temp->next; // 1. Save the next node's address safely
        delete temp;                 // 2. Delete the current node safely
        temp = nextNode;             // 3. Move temp to the saved address
    }
    head = nullptr;
}


// for all above code we also can use non vpid function which will eventyually return head (accordingly)
int main()
{
    // --- STEP 1: INITIALIZE AND PERFORM ALL YOUR INSERTIONS ---
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    head->next = second;

    cout << "Original list: "; 
    traverse(head);

    insertAtHead(head, 5);
    insertAtHead(head, 7);
    cout << "List after insertion at head: ";
    traverse(head);

    insertAtTail(head, 19);
    cout << "List after insertion at tail: ";
    traverse(head);

    insertAtMid(head, 24);
    cout << "List after insertion at mid: ";
    traverse(head);

    insertAtPosition(head, 25, 3);
    cout << "List after insertion at kth position (Pos 3): ";
    traverse(head);
    // Expected List State here: 7->5->25->10->24->20->19->nullptr


    // --- STEP 2: EXECUTE YOUR DELETIONS ---
    cout << "\n--- STARTING DELETION OPERATIONS ---\n";

    // 1. Test your Deletion at Head
    deletionAtHead(head);
    cout << "After Deletion at Head (Removed 7): ";
    traverse(head);

    // 2. Test your Deletion at Tail
    deletionAtTail(head);
    cout << "After Deletion at Tail (Removed 19): ";
    traverse(head);

    // 3. Test your Deletion at Position K 
    // (Make sure to fix the 'temp->next == nullptr' typo in deletionAtKpos before running)
    deletionAtKpos(head, 2); 
    cout << "After Deletion at Position K (Pos 2, Removed 25): ";
    traverse(head);

    // 4. Test your Deletion at True Middle (Your custom implementation)
    deletionAtMid(head);
    cout << "After Deletion at True Middle: ";
    traverse(head);


    // --- STEP 3: SAFE MEMORY CLEANUP ---
    cout << "\nCleaning up remaining memory...\n";
    freeList(head); 
    cout << "Final List State: ";
    traverse(head);

    return 0; 
}
