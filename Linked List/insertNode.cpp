
Node* insert(Node* head, int i, int data)
{
    Node* newNode = new Node(data);
    if (i == 0)
    {
        newNode -> next = head;
        return newNode; 
    }
    Node* temp = head;
    for (int k = 0; k < i && temp!= NULL; k++)
    {
        temp = temp -> next;
    }
    if (temp != NULL)
    {
        Node* tempa = temp -> next;
        temp -> next = newNode;
        newNode -> next = tempa;
    }
    return head;
}

Node* insert_rec(Node* head, int i, int data)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        Node* newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }
    Node* small = insert_rec(head -> next, i - 1, data);
    head -> next = small;
    return head;
}



