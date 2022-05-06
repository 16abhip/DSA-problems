#include "length.cpp"

void printRev_rec(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    printRev_rec(head -> next);
    cout << head -> data << " ";
}


void printRev(Node* head)
{
    int l = len(head);
    while (l != 0)
    {
        Node* temp = head;
        for(int i = 1; i < l; i++)
        {
            temp = temp -> next;
        }
        cout << temp -> data << " ";
        l--;
    }    
}
