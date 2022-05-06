#include "mergeTwoSortedLinkedLists.cpp"
#include "midNode.cpp"

Node* mergeSort(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* mid = midNode(head);
    Node* sec = mid -> next;
    mid -> next = NULL;
    Node* head1 = mergeSort(head);
    Node* head2 = mergeSort(sec);
    return mergeTwoSortedLinkedLists(head1, head2);
}
