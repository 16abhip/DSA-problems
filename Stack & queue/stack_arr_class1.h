
// with fix capacity
class Stack
{
    int size;
    int currentIndex;
    int nextIndex;
    int* arr;
    int capacity;
    public:

    Stack(int capacity)
    {
        this -> capacity = capacity;
        arr = new int[capacity];
        currentIndex = -1;
        size = 0;
        nextIndex = 0;
    }
    int get_size()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    int top()
    {
        if (size == 0)
        {
            cout << "Stack is Empty!" << endl;
            return -10101;
        }
        return arr[currentIndex];
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "Stack is Empty!" << endl;
            return -10101;
        }
        int ans = arr[currentIndex];
        nextIndex = currentIndex;
        currentIndex -= 1;
        size--;
        return ans;
    }
    void push(int data)
    {
        if (size == capacity)
        {
            cout << "Stack is FULL!" << endl;
            return;
        }
        arr[nextIndex++] = data;
        currentIndex++;
        size++;
    }
};

