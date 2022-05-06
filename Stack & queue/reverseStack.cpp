#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra)
{
    while (input.size() != 0)
    {
        extra.push(input.top());
        input.pop();
    }
    stack<int> temp;
    while (extra.size() != 0)
    {
        temp.push(extra.top());
        extra.pop();
    }
    while (temp.size() != 0)
    {
        input.push(temp.top());
        temp.pop();
    }
}