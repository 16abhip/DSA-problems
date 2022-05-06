
int print_ith_rec(Node *head,int i)
{
    if (head == NULL)
    {
        return;
    }
    if (i == 0)
    {
        cout << head -> data << endl;
        return;
    }
    print_ith_rec(head -> next, i - 1);
}

int print_ith(Node* head, int i)
{
    for (int k = 0; k < i && head != NULL; k++)
    {
        head = head -> next;
    }
    if (head != NULL)
    {
        cout << head -> data << endl;
    }
}