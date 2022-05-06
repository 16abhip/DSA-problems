
#include <queue>
#include <stack>

// in rec... stack is used.. so think about it.. 

void reverseQueue_rec(queue<int> &input)
{
    if (input.size() <= 1)
    {
        return;
    }
    int first = input.front();
    input.pop();
    reverseQueue_rec(input);
    input.push(first);
}

void reverseQueue(queue<int> &input)
{
    stack<int> temp;
    while (input.size() != 0)
    {
        temp.push(input.front());
        input.pop();
    }
    while (temp.size() != 0)
    {
        input.push(temp.top());
        temp.pop();
    }
}