#include "length.cpp"

Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL || head -> next == NULL || n == 0)
    {
        return head;
    }
    Node* tail = head;
    while(tail -> next != NULL)
    {
        tail = tail -> next;
    }
    int l = len(head);
    l = l - n;
    Node* temp = head;
    for (int i = 1; i < l; i++)
    {
        temp = temp -> next;
    }
    Node* ans = temp -> next;
    temp -> next = NULL;
    tail -> next = head;
    return ans;   
}