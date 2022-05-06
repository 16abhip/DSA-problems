
// Node class
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
}
// stack using LL
class Stack
{
    int size;
    Node* head;
    public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(int data)
    {
        Node* newNode = new Node(data);
        if (head != NULL)
        {
            newNode -> next = head;
        }
        head = newNode;
        size++;
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "Stack is Empty! " << endl;
            return -10101;
        }
        Node* headNext = head -> next;
        int ans = head -> data;
        delete head;
        head = headNext;
        size--;
        return ans;
    }
    int top()
    {
        if (size == 0)
        {
            cout << "Stack is Empty! " << endl;
            return -10101;
        }
        return head -> data;
    }
};