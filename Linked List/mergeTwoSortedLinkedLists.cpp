
Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node* head = NULL;
    if (head1 -> data  <= head2 -> data)
    {
        head = head1;
        head1 = head1 -> next;
    }
    else
    {
        head = head2;
        head2 = head2 -> next;
    }
    Node* tail = head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 -> data <= head2 -> data)
        {
            tail -> next = head1;
            head1 = head1 -> next;
        }
        else
        {
            tail -> next = head2;
            head2 = head2 -> next;
        }
        tail = tail -> next;
    }
    if (head1 != NULL)
    {
        tail -> next = head1;
    }
    if (head2 != NULL)
    {
        tail -> next = head2;
    }
    return head;
}