#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool checkRedundantBrackets(string str)
{
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ')')
        {
            s.push(str[i]);
        }
        else
        {
            int count = 0;
            char front = s.top();
            while (front != '(')
            {
                count++;
                s.pop();
                front = s.top();
            }
            s.pop();
            if (count <= 1)
            {
                return true;
            }
        }
    }
    return false;
}