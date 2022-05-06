#include <stack>

bool isBalanced(string str)
{
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            s.push('(');
        }
        else
        {
            if (s.size() == 0)
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    if (s.size() != 0)
    {
        return false;
    }
    return true;
}