
Node* swapNodes_rec(Node* head, int i, int j)
{
    if (i == j || head == NULL || head -> next == NULL)
    {
        return head;
    }
    if (i > j)
    {
        int a = i; 
        i = j;
        j = a;
    }
    Node* smalloutput = swapNodes_rec(head -> next, i - 1, j - 1);
    head -> next = smalloutput;
    if (i != 0)
    {
        return head;
    }
    Node* temp = head;
    Node* pre = NULL;
    for (int k = 0; k < j && temp != NULL; k++)
    {
        pre = temp;
        temp = temp -> next;
    }
    if (temp == NULL)
    {
        return head;
    }
    if (head == pre)
    {
        head -> next = head -> next -> next;
        temp -> next = head;
        return temp;
    }
    if (temp -> next == NULL)
    {
        pre -> next = head;
        temp -> next = head -> next;
        head -> next = NULL;
        return temp;
    }
    Node* headNext = head -> next;
    pre -> next = head;
    head -> next = temp -> next;
    temp -> next = headNext;
    return temp;
    
}


Node* swapNodes(Node* head, int i, int j)
{
    if (i == j || head == NULL || head -> next == NULL)
    {
        return head;
    }
    if (i > j)
    {
        int a = i;
        i = j;
        j = a;
    }
    Node* temp1 = head;
    Node* pre1 = NULL;
    for (int  k = 0; k < i && temp1 != NULL; k++)
    {
        pre1 = temp1;
        temp1 = temp1 -> next;
    }
    if (temp1 == NULL)
    {
        return head;
    }
    Node* temp2 = head;
    Node* pre2 = NULL;
    for (int  k = 0; k < j && temp2 != NULL; k++)
    {
        pre2 = temp2;
        temp2 = temp2 -> next;
    }
    if (temp2 == NULL)
    {
        return head;
    }
    if (i == 0 && j - i != 1)
    {
        Node* headNext = head -> next;
        pre2 -> next = head;
        head -> next = temp2 -> next;
        temp2 -> next = headNext;
        return temp2;
    }
    if (i == 0 && j - i == 1)
    {
        head -> next = head -> next -> next;
        temp2 -> next = head;
        return temp2;
    }
    if (j - i == 1)
    {
        temp1 -> next = temp1 -> next -> next;
        temp2 -> next = temp1;
        pre1 -> next = temp2;
        return head;
    }
    Node* n1 = temp1 -> next;
    Node* n2 = temp2 -> next;
    pre1 -> next = temp2;
    temp2 -> next = n1;
    pre2 -> next = temp1;
    temp1 -> next = n2;
    return head;
}