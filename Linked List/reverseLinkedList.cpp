
class Pair
{
    public:
    Node* head;
    Node* tail;
    Pair(Node* head, Node* tail)
    {
        this -> head = head;
        this -> tail = tail;
    }
};

Pair reverseLinkedList_pair(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        Pair ans(head, head);
        return ans;
    }
    Pair smalloutput = reverseLinkedList_pair(head -> next);
    smalloutput.tail -> next = head;
    head -> next = NULL;
    smalloutput.tail = smalloutput.tail -> next;
    return smalloutput;
}

Node* reverseLinkedList_rec(Node* head)
{
    return reverseLinkedList_pair(head).head;
}

Node* reverseLinkedList_Rec(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* small = reverseLinkedList_Rec(head -> next);
    Node* tail = small;
    while (tail -> next != NULL)
    {
        tail = tail -> next;
    }
    tail -> next = head;
    head -> next = NULL;
    tail = tail -> next;
    return small;    
}


Node* reverseLinkedListRec(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* small = reverseLinkedListRec(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return small;
}

Node* reverseLinkedList(Node* head)
{
    Node* fast = head;
    head = NULL;
    while (fast != NULL)
    {
        Node* temp_f = fast -> next;
        fast -> next = head;
        head = fast;
        fast = temp_f;
    }
    return head;    
}