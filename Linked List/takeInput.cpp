#include "LL_class.h"
Node* takeInput()
{
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while (data != -1)
    {
        Node* n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail -> next = n;
            tail = tail -> next;
        }
        cin >> data;        
    }
    return head;
}