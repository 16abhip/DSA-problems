
int len_rec(Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    return len_rec(head -> next) + 1;
}

int len(Node* head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head -> next;
    }
    return l;    
}