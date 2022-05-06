#include "length.cpp"

Node* rev(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* small = rev(head -> next);
    Node* tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    
    return small;
}

bool isPalindrome_better(Node *head)
{
    if (head == NULL || head -> next == NULL)
    {
        return true;
    }
    int l = len(head);
    Node* temp = head;
    for (int i = 1; i < (l/2); i++)
    {
        temp = temp -> next;
    }
    Node* sec = NULL;
    Node* revs = NULL;
    if (l%2 == 0)
    {
        sec = temp -> next;
        temp -> next = NULL;
        
    }
    else
    {
        sec = temp -> next -> next;
        temp -> next = NULL;
        
    }
    revs = rev(sec);
    while(head != NULL)
    {
        if (head -> data != revs -> data)
        {
            return false;
        }
        head = head -> next;
        revs = revs -> next;
    }
    return true;
    
    
    
}

bool isPalindrome(Node* head)
{

    if (head == NULL)
    {
        return true;
    }
    int l = len(head);
    while (l >= l/2)
    {
        Node* temp = head;
        for (int i = 1;i < l; i++)
        {
            temp = temp -> next;
        }
        if (head -> data != temp -> data)
        {
            return false;
        }
        l--;
        l--;
        head = head -> next;
    }
    return true;
} 

// without length fun

bool isPalindrome_best(Node *head)
{
    if (head == NULL || head -> next == NULL)
    {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    
    
        Node* small = slow -> next;
        slow -> next = NULL;
		Node* revs = rev(small);
    
    while(revs != NULL)
    {
        if (head -> data != revs -> data)
        {
            return false;
        }
        head = head -> next;
        revs = revs -> next;
    }
    return true;
}