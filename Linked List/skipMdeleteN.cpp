
Node* skipMdeleteN(Node* head, int m, int n)
{
    if(m == 0 || head == NULL)
    {
        return NULL;
    }
    if (n == 0)
    {
        return head;
    }
    Node* h = head;
    Node* t = head;
    while (head != NULL)
    {
        for (int i = 1; i < m && t != NULL; i++)
        {
            t = t -> next;
        }
        if (t == NULL)
        {
            return h;
        }        
        Node* temp = t -> next;
        for (int i = 0; i < n && temp != NULL; i++)
        {
            Node* temp1 = temp -> next;
            delete temp;
            temp = temp -> next;
        }
        t -> next = temp;
        t = t -> next;
        head = t;
    }
    return h;
}