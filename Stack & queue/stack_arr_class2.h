// dynamic array
class Stack
{
    int size;
    int nextIndex;
    int currentIndex;
    int* arr;
    int currentCap;
    public:
    Stack()
    {
        size = 0;
        nextIndex = 0;
        currentIndex = -1;
        currentCap = 5;
        arr = new int[currentCap];
    }
    int get_size()
    {
        return size;
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "Stack is Empty!" << endl;
            return -10101;
        }
        int ans = arr[currentIndex];
        size--;
        nextIndex = currentIndex;
        currentIndex--;
        return ans;
    }
    void push(int data)
    {
        if (currentCap == size)
        {
            int *newarr = new int[2*size];
            currentCap *= 2;
            for (int i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
            }
            delete []arr;
            arr = newarr;
        }
        size++;
        arr[nextIndex++] = data;
        currentIndex++;
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
};
