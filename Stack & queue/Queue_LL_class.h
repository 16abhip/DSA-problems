#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

class Queue
{
    int size;
    Node* head;
    Node* tail;
    Queue()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return -10101;
        }
        return head -> data;
    }
    void enqueue(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail -> next = newNode;
            tail = tail -> next;
        }
        size++;
    }
    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return -10101;
        }
        int ans = head -> data;
        Node* toDelete = head;
        head = head -> next;
        delete toDelete;
        size--;
        return ans;
    }
};


