#include "takeInput.cpp"

// You have been given a singly linked list of integers where the elements are sorted 
// in ascending order. Write a function that removes the consecutive 
// duplicate values such that the given list only contains unique 
// elements and returns the head to the updated list.

Node* removeDuplicates_rec(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* small = removeDuplicates_rec(head -> next);
    if (small -> data == head -> data)
    {
        delete head;
        head = small;
    }
    else
    {
        head -> next = small;
    }
    return head;
}

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* temp = head;
    while(temp -> next != NULL)
    {
        if (temp -> data == temp -> next -> data)
        {
            temp -> next = temp -> next -> next;
        }
        else
        {
            temp = temp -> next;
        }
    }
    return head;
}