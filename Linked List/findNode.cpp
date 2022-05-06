
int findNode(Node* head, int n)
{
    for (int i = 0; head != NULL; i++)
    {
        if (head -> data == n)
        {
            return i;
        }
        head = head -> next;
    }
    return -1;
}

int findNode_rec(Node* head, int n)
{
    if (head == NULL)
    {
        return -1;
    }
    if (n == head -> data)
    {
        return 0;
    }
    int small = findNode_rec(head -> next, n);
    if (small != -1)
    {
        small += 1;
    }
    return small;
}