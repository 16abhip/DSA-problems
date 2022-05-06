
Node* deleteNode(Node* head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    Node* temp = head;
    if (i == 0)
    {
        head = head -> next;
        delete temp;
        return head;
    }
    for (int k = 1; k < i && temp -> next != NULL; k++)
    {
        temp = temp -> next;
    }
    if (temp -> next != NULL)
    {
        Node* to = temp -> next;
        Node* toto = to -> next;
        temp -> next = toto;
        delete to;
    }
    return head;
}

Node* deleteNode_rec(Node* head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* small = deleteNode_rec(head-> next, i - 1);
    head -> next = small;
    return head;
}