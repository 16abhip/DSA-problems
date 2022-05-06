
Node* evenAfterOdd(Node* head)
{
    Node* head_odd = NULL;
    Node* tail_odd = NULL;

    Node* head_even = NULL;
    Node* tail_even = NULL;
    Node* temp = head;
    while (head != NULL)
    {
        if (head -> data % 2 != 0)
        {
            if (head_odd == NULL)
            {
                head_odd = head;
                tail_odd = head;
            }
            else
            {
                tail_odd -> next = head;
                tail_odd = tail_odd -> next;
            }
        }
        else
        {
            if(head_even == NULL)
            {
                head_even = head;
                tail_even = head;
            }
            else
            {
                tail_even -> next = head;
                tail_even = tail_even -> next;
            }
        }
        head = head -> next;
    }
    if(head_even == NULL || head_odd == NULL)
    {
        return temp;
    }
    tail_odd -> next = head_even;
    tail_even -> next = NULL;
    return head_odd;    
}