#include "reverseLinkedList.cpp"

Node* kReverse(Node* head, int k)
{
    if (k <= 1 || head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++)
    {
        temp = temp -> next;
    }
    if (temp == NULL)
    {
        return reverseLinkedList(head);
    }
    Node* small = kReverse(temp -> next, k);
    temp -> next = NULL;
    Node* revs = reverseLinkedList(head);
    head -> next = small;
    return revs;    
}